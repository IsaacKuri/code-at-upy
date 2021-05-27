#include "project.h"

char codigo[32] = "WRE,08,08,08,08,08,08,08,08,08,F";
char check[32] = "00000000000000000000000000000000";
char foo;
int cs = 0;
int pass = 1;
int comas = 0;
int read = 1;
int offset = 8;
int adc[4];
//Prototipo de funciones
char intochar();
void intostring();
int chartoint();
int stringtoint();
CY_ISR_PROTO(com_handler);
int main(void)
{
    CyGlobalIntEnable;
    LCD_Start();
    UART_Start();
    ADC_Start();
    ADC_StartConvert();
    Clock_1_Start();
    PWM_1_Start();
    PWM_2_Start();
    PWM_3_Start();
    PWM_4_Start();
    PWM_5_Start();
    PWM_6_Start();
    PWM_7_Start();
    PWM_8_Start();
    PWM_9_Start();
    com_StartEx(com_handler);
    com_ClearPending();
    for(;;)
    {
        //Read
        adc[0] = (int)(((0.0055)*ADC_GetResult16(0)) + offset);
        adc[1] = (int)(((0.0055)*ADC_GetResult16(1)) + offset);
        adc[2] = (int)(((0.0055)*ADC_GetResult16(2)) + offset);
        adc[3] = (int)(((0.0055)*ADC_GetResult16(3)) + offset);
        //Manual
        PWM_1_WriteCompare(stringtoint(&codigo[0],4,5));
        PWM_2_WriteCompare(stringtoint(&codigo[0],7,8));
        PWM_3_WriteCompare(stringtoint(&codigo[0],10,11));
        PWM_4_WriteCompare(stringtoint(&codigo[0],13,14));
        PWM_5_WriteCompare(stringtoint(&codigo[0],16,17));
        PWM_9_WriteCompare(stringtoint(&codigo[0],28,29));
        
        if(MODE_Read() == 1){
         //Routine Mode
        PWM_6_WriteCompare(stringtoint(&codigo[0],19,20));
        PWM_7_WriteCompare(stringtoint(&codigo[0],22,23));
        PWM_8_WriteCompare(stringtoint(&codigo[0],25,26));
        }
        else{
        PWM_6_WriteCompare(adc[0]);
        PWM_7_WriteCompare(adc[1]);
        PWM_8_WriteCompare(adc[2]); 
        }
        
        LCD_ClearDisplay();
        LCD_Position(0,0);
        LCD_PrintString(codigo);
        LCD_Position(1,0);
        LCD_PrintNumber(comas);
        CyDelay(30);
    }
}

CY_ISR(com_handler){
    //UART_PutChar('r');
    foo = UART_GetChar();
    if(foo == 'W'){
        cs = 0;
        pass = 1;
        comas = 0;
        read = 1;
    }
    if(foo == ','){
        comas++;
    }
    if(read == 1){
     check[cs] = foo;
    }
    if(cs == 3){
        if(check[0] != 'W'){ pass = 0;}
        if(check[1] != 'R'){ pass = 0;}
        if(check[2] != 'E'){ pass = 0;}
    }
    if(cs == 31){
        if(check[0] != 'W'){ pass = 0;}
        if(check[1] != 'R'){ pass = 0;}
        if(check[2] != 'E'){ pass = 0;}
    }
    if((foo == 'F')&&(cs==31)&&(pass == 1)&&(comas == 10)){
         read = 0;
        for(int i = 0; i < 32; i++){
            codigo[i] = check[i];
        }
    }
    cs++;
    com_ClearPending();
}



//Funciones de conversion
char intochar(int temp){
    if (temp == 0){ return '0'; }
    else if(temp == 1){return '1';}
    else if(temp == 2){return '2';}
    else if(temp == 3){return '3';}
    else if(temp == 4){return '4';}
    else if(temp == 5){return '5';}
    else if(temp == 6){return '6';}
    else if(temp == 7){return '7';}
    else if(temp == 8){return '8';}
    else if(temp == 9){return '9';}
    else {return 'x';} 
}

void intostring(int temp, char *str){
    *str = intochar((temp/10)%10);
    str++;
    *str = intochar(temp%10);
}
//Funcion de str a int

int stringtoint(char *str, int lv, int hv){
    int pos = 1;
    char temp;
    int numtemp;
    int result = 0;
    
    for(int i = lv; i <= hv; i++){
    temp = *(str + i);
     if (temp == '0'){ numtemp = 0; }
    else if(temp == '1'){numtemp = 1;}
    else if(temp == '2'){numtemp = 2;}
    else if(temp == '3'){numtemp = 3;}
    else if(temp == '4'){numtemp = 4;}
    else if(temp == '5'){numtemp = 5;}
    else if(temp == '6'){numtemp = 6;}
    else if(temp == '7'){numtemp = 7;}
    else if(temp == '8'){numtemp = 8;}
    else if(temp == '9'){numtemp = 9;}
    else {numtemp = 0;}
    if(pos == 1){result += numtemp*10;}
    if(pos == 0){result += numtemp;}
    pos--;
    }
    return result;
}