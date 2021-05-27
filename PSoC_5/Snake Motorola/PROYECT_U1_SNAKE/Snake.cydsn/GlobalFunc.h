//Global Functions
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
//Basic Conversion
int Pos_2D(int posx, int posy){
    int c = 16*posy + posx; 
    return c;
}

int RandNum(int lower,int upper){
    int num = (rand() % (upper - lower + 1)) + lower; 
    return num;
}