#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "GlobalDef.h"
#include "GlobalFunc.h"
#include "PixelEngine.h"


//Coordinate Vector for the Snake
struct snake_xy {
	int x, y;
};

//Data Structure of the Snake
const int snake_size = snake_board_area;
const int grid_size = snake_board_area;
//Max Amount of Baits
const int bait_size = bait_size_u;

struct snake_xy snake[snake_board_area];
struct snake_xy bait[bait_size_u];

int snake_head = 0;
int snake_tail = 0;
int match_score = 0;

int score_ten_t = 0;
int period_offs = 0;

char last_dir = 'D';
char cur_dir = 'D';


int MapBuffer[snake_board_height][snake_board_length];

//Init all baits as null
void Clear_Baits(){
    for(int i = 0; i < bait_size; i++){
        bait[i].x = -1;
        bait[i].y = -1;
    }
}

void Start_Snake(int Board[snake_board_height][snake_board_length]) {
    match_score = 0;
    score_ten_t = 0;
    period_offs = 0;
    Clear_Baits();
    //Passing a Map for the Snake
    for(int y = 0;y < snake_board_height; y++){
        for(int x = 0; x < snake_board_length; x++){
            MapBuffer[y][x] = Board[y][x];
        }
    }
    //Initial positions
	snake[0].x = 10; snake[0].y = 7;
	snake[1].x = 10; snake[1].y = 6;
	snake[2].x = 10; snake[2].y = 5;
    //Index for the snake, must equal the max index len and the initial len.
	snake_head = 0;
	snake_tail = 2;
    //Starting direction of the snake.
	cur_dir = 'D';
}

void add_bait() {
	for (int i = 0; i < bait_size; i++) {
        //A -1 indicates an empty slot
		if (bait[i].x == -1) {
			bait[i].x = RandNum(1,snake_board_length - 1);
			bait[i].y = RandNum(1,snake_board_height - 1);
            //Check if bait spawned in the snake, so try again, might fail but its unlikely
            for (int j = 0; j < snake_tail; j++) {
		    if ((snake[j].x == bait[i].x) && (snake[j].y == bait[i].y)) {
			        bait[i].x = RandNum(1,snake_board_length - 1);
			        bait[i].y = RandNum(1,snake_board_height - 1);
		        }
	        }
			break;
		}
	}
}

void Clear_Screen(){
    //Clear EveryLast Frame that Isn't a wall;
    for(int y = 0; y < snake_board_height; y++){
        for(int x = 0; x < snake_board_length;x++){
            if(MapBuffer[y][x] != 3){
                MapBuffer[y][x] = 0;
            }
        }
    }
}
void draw_score() {
    LCD_Position(0,5);
    LCD_PrintString("SCORE");
    LCD_Position(1,5);
    LCD_PrintNumber(match_score);
}
void draw_snake() {
    Clear_Screen();
    //Basically a render function for the snake.
	int thead = 0; //Short for The Head.
    
	for (;;) {
		int x = snake[thead].x;
		int y = snake[thead].y;
       
	    MapBuffer[y][x] = 1;

		if (thead == snake_tail) {break;}
		thead++;
	}
    //Drawing Baits
	for (int i = 0; i < bait_size; i++) {
		if (bait[i].x >= 0) {
			MapBuffer[bait[i].y][bait[i].x] = 1;
		}
	}
    //Display Array
    LCD_ClearDisplay();
    draw_score();
    ShowBoard(MapBuffer);
}
void change_dir(char dir_c){
    
    if((dir_c == 'U') &&(last_dir != 'D')){
        cur_dir = dir_c;
    }
    if((dir_c == 'D') &&(last_dir != 'U')){
        cur_dir = dir_c;
    }
    if((dir_c == 'L') &&(last_dir != 'R')){
        cur_dir = dir_c;
    }
    if((dir_c == 'R') &&(last_dir != 'L')){
        cur_dir = dir_c;
    }
    last_dir = dir_c;
}
//Returns true when a loosing condition happens
bool move_snake() {
	struct snake_xy cur = snake[snake_head];
	struct snake_xy temp = cur;
    struct snake_xy snake_temp_old[snake_tail + 1];
    //Determining the direction
	switch (cur_dir) {
	case 'U':
		temp.y--;
		break;
	case 'D':
		temp.y++;
		break;
	case 'L':
		temp.x--;
		break;
	case 'R':
		temp.x++;
		break;
	}
    //Filtering
    if(snake_board_length - 1 <= temp.x){
        temp.x = 1;
        return true;
    }
    else if(temp.x < 1){
        temp.x = snake_board_length - 1;
        return true;
    }
    
    if(snake_board_height - 1 <= temp.y){
        temp.y = 1;
        return true;
    }
    else if(temp.y < 1){
        temp.y = snake_board_height - 1;
        return true;
    }
	
    //Check Killing Self
    for (int i = 1; i < snake_tail; i++) {
		if ((snake[i].x == temp.x) && (snake[i].y == temp.y)) {
			return true;
		}
	}
    //Check for Bait Eating
	for (int i = 0; i < bait_size; i++) {
		if ((bait[i].x == temp.x) && (bait[i].y == temp.y)) {
            //Add Score
            match_score++;
            score_ten_t++;
            if(score_ten_t == score_to_speed){
                score_ten_t = 0;
                period_offs++;
            }
			//Remove the bait.
			bait[i].x = -1;
			bait[i].y = -1;
            
            //Movement Algorithm for bait eating
            for(int i = 0; i < snake_tail + 1; i++){
                snake_temp_old[i].x = snake[i].x;
                snake_temp_old[i].y = snake[i].y;
                }
            
            snake[snake_head].x = temp.x;
            snake[snake_head].y = temp.y;
            for(int i = 0; i <= snake_tail; i++){
                snake[i + 1].x = snake_temp_old[i].x;
                snake[i + 1].y = snake_temp_old[i].y;
                }
            snake_tail++;
            return false;
		    }
	}
    
    //Movement Algorithm
    for(int i = 0; i < snake_tail + 1; i++){
        snake_temp_old[i].x = snake[i].x;
        snake_temp_old[i].y = snake[i].y;
    }
    snake[snake_head].x = temp.x;
    snake[snake_head].y = temp.y;
    for(int i = 0; i < snake_tail; i++){
        snake[i + 1].x = snake_temp_old[i].x;
        snake[i + 1].y = snake_temp_old[i].y;
    }
	return false;
}