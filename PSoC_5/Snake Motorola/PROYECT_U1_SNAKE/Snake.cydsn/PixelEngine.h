//The following header contains functions to support a Pixel Engine for the Hitachi LCD 16x2 Module
//Written By: Isaac Kuri.
#include "GlobalDef.h"
#include "project.h"

uint8 lcd_ram[lcd_ram_size];

void RenderBoard(int posx);
uint8 PosToByte(int var_);

void ShowBoard(int Board[snake_board_height][snake_board_length]){
    //Transforms a given board to a uint8 64bytes format.
    int sub_x = 0;
    int sub_y = 0;
    int seg_line = 0;
    int seg_tracker = 0;
    uint8 ram_buff = 0;
    
    for(int i = 0; i < lcd_ram_size; i++){
        for(int x = 0; x < segment_length; x++){
            if(Board[sub_y][sub_x + x] >= 1){
            ram_buff += PosToByte(x);
            }
        }
        lcd_ram[i] = ram_buff;
        ram_buff = 0;
        if(seg_line < segment_height - 1){
            seg_line++;
            sub_y++;
        }
        else{
            seg_line = 0;
            seg_tracker++;
            sub_x += segment_length;
            if(seg_tracker == 4){
                sub_x =0;
            }
            if(seg_tracker > 3){
                sub_y = segment_height;
            }
            else {
                sub_y = 0;
            }
        }
    }
    RenderBoard(0);
}

void RenderBoard(int posx){
    //load LCD RAM and Display
    //LCD_ClearDisplay();
    LCD_LoadCustomFonts(lcd_ram);

    LCD_Position(0, posx);
    LCD_PutChar(LCD_CUSTOM_0);
    LCD_Position(0, posx + 1);
    LCD_PutChar(LCD_CUSTOM_1);
    LCD_Position(0, posx + 2);
    LCD_PutChar(LCD_CUSTOM_2);
    LCD_Position(0, posx + 3);
    LCD_PutChar(LCD_CUSTOM_3);
    LCD_Position(1, posx);
    LCD_PutChar(LCD_CUSTOM_4);
    LCD_Position(1, posx + 1);
    LCD_PutChar(LCD_CUSTOM_5);
    LCD_Position(1, posx + 2);
    LCD_PutChar(LCD_CUSTOM_6);
    LCD_Position(1, posx + 3);
    LCD_PutChar(LCD_CUSTOM_7);
}

uint8 PosToByte(int var_){
    //Does the position correction to bytes.
    uint8 result = 0b0;
    if(var_ == 0){
        result = 0b10000;
    }
    if(var_ == 1){
        result = 0b1000;
    }
    if(var_ == 2){
        result = 0b100;
    }
    if(var_ == 3){
        result = 0b10;
    }
    if(var_ == 4){
        result = 0b1;
    }
    return result;
}