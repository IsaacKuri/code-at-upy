#include "project.h"
char codigo[32] = "WRE,00,00,00,00,00,00,00,00,00,F";

char PWM1[2] = "00"; //Pulgar
char PWM2[2] = "00"; //Primero
char PWM3[2] = "00"; //Enmedio
char PWM4[2] = "00"; //Antemenique
char PWM5[2] = "00"; //Menique
char PWM6[2] = "08"; // Rotacion
char PWM7[2] = "08"; // Codo
char PWM8[2] = "08"; // Muñeca inclinar
char PWM9[2] = "00"; // Muñeca rotar

int ADCV[6];
int offset = 8;
int calacc = 0;

int sizerut = 17; //Necesita tener el mismo largo que las rutinas
//Rutina Dedos
int rutina[14][10] = { 
    {8,8,8,8,8,20,20,20,20,1000},
    {17,25,8,8,8,20,20,20,8,1000},
    {19,8,25,8,8,20,20,20,15,1000},
    {20,8,8,25,8,20,20,20,18,1000},
    {24,8,8,8,28,20,20,20,25,1000},
    {8,8,8,8,8,20,20,20,20,1000},
    {8,8,30,30,8,15,20,25,20,1000},
    {24,8,30,30,8,20,20,20,20,1000},
    {8,8,8,8,8,20,20,20,8,1000},
    {25,8,8,30,30,20,20,20,31,1000},
    {8,8,8,8,8,20,20,20,20,1000},
    {8,25,25,25,25,20,20,14,10,500},
    {8,25,25,25,25,20,20,18,10,500},
    {8,25,25,25,25,20,20,14,10,500},
    
};
//Rutina Martillo
int rutina1[17][10] = { 
    {8,8,8,8,8,20,20,20,20,1000},
    {8,8,8,8,8,20,24,20,20,1000},
    {8,8,8,8,8,20,26,20,10,1000},
    {8,8,8,8,8,18,26,20,10,1000},
    {8,8,8,8,8,14,26,20,10,1000},
    {8,8,8,8,8,14,24,20,10,1000},
    {28,28,28,28,28,14,24,20,10,1000},
    {28,28,28,28,28,14,24,18,28,1000},
    {28,28,28,28,28,14,22,23,28,1000},
    {28,28,28,28,28,14,22,18,28,1000},
    {28,28,28,28,28,14,22,23,28,1000},
    {28,28,28,28,28,14,22,18,28,1000},
    {28,28,28,28,28,14,22,23,28,1000},
    {28,28,28,28,28,14,22,18,28,1000},
    {28,28,28,28,28,14,22,20,20,1000},
    {8,8,8,8,8,20,20,20,20,1000},
    {28,28,8,8,28,20,20,20,20,1000},
};
//Prototipo de funciones
char intochar();
void intostring();
int chartoint();
int stringtoint();
long map();
void movements();

int main(void)
{
    CyGlobalIntEnable;
    LCD_Start();
    ADC_Start();
    ADC_StartConvert();
    UART_Start();
    for(;;)
    {
        //Debugging
        LCD_ClearDisplay();
        LCD_Position(0,0); 
        LCD_PrintString(codigo);
       // LCD_PrintNumber( ADCV[5] );
        
        //ADC Multiplexing Reading
        if(MODE_Read() == 0){
        ADCV[0] = ADC_GetResult16(0);
        ADCV[0] = (int)(((0.0055)*ADCV[0]) + offset); // converting the ADC value from 8 to 30 | (f(x) = 0.0055(x) + 8)
        intostring(ADCV[0],&PWM1[0]);
        CyDelay(5);

        ADCV[1] = ADC_GetResult16(1);
        ADCV[1] = (int)(((0.0055)*ADCV[1]) + offset); // converting the ADC value from 8 to 30 | (f(x) = 0.0055(x) + 8)
        intostring(ADCV[1],&PWM2[0]);
        CyDelay(5);

        ADCV[2] = ADC_GetResult16(2);
        ADCV[2] = (int)(((0.0055)*ADCV[2]) + offset); // converting the ADC value from 8 to 30 | (f(x) = 0.0055(x) + 8)
        intostring(ADCV[2],&PWM3[0]);
        CyDelay(5);

        ADCV[3] = ADC_GetResult16(3);
        ADCV[3] = (int)(((0.0055)*ADCV[3]) + offset); // converting the ADC value from 8 to 30 | (f(x) = 0.0055(x) + 8)
        intostring(ADCV[3],&PWM4[0]);
        CyDelay(5);

        ADCV[4] = ADC_GetResult16(4);
        ADCV[4] = (int)(((0.0055)*ADCV[4]) + offset); // converting the ADC value from 8 to 30 | (f(x) = 0.0055(x) + 8)
        intostring(ADCV[4],&PWM5[0]);
        CyDelay(5);
        
        ADCV[5] = (int)map(ADC_GetResult16(5), 1100,1600, 31, 8); //Acelerometro
        if(ADCV[5] < 8 ){
            ADCV[5] = 8;
        }
        if(ADCV[5] > 31){
            ADCV[5] = 31;
        }
        intostring(ADCV[5],&PWM9[0]);
        CyDelay(5);
        
        //String Inyection
        codigo[4] = PWM1[0];
        codigo[5] = PWM1[1];
        
        codigo[7] = PWM2[0];
        codigo[8] = PWM2[1];
        
        codigo[10] = PWM3[0];
        codigo[11] = PWM3[1];
        
        codigo[13] = PWM4[0];
        codigo[14] = PWM4[1];
        
        codigo[16] = PWM5[0];
        codigo[17] = PWM5[1];
        
        codigo[19] = PWM6[0];
        codigo[20] = PWM6[1];
        
        codigo[22] = PWM7[0];
        codigo[23] = PWM7[1];
        
        codigo[25] = PWM8[0];
        codigo[26] = PWM8[1];
        
        codigo[28] = PWM9[0];
        codigo[29] = PWM9[1];
        //-------------//
        
        CyDelay(10);
        UART_PutString(codigo);
        
        }
        if(MODE_Read() == 1){
            LCD_Position(1,0);
            LCD_PrintString("Rutine Mode");
            movements(rutina1,sizerut);
        }
        
        
    }
    
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
//Funcion rateada de arduino
long map(long x, long in_min, long in_max, long out_min, long out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
//Ejecucion de rutinas
void movements(int instructions[][10], int size){
        for(int i = 0; i < size; i++){
        intostring(instructions[i][0],&PWM1[0]);
        intostring(instructions[i][1],&PWM2[0]);
        intostring(instructions[i][2],&PWM3[0]);
        intostring(instructions[i][3],&PWM4[0]);
        intostring(instructions[i][4],&PWM5[0]);
        intostring(instructions[i][5],&PWM6[0]);
        intostring(instructions[i][6],&PWM7[0]);
        intostring(instructions[i][7],&PWM8[0]);
        intostring(instructions[i][8],&PWM9[0]);
        
        //String Inyection
        codigo[4] = PWM1[0];
        codigo[5] = PWM1[1];
        
        codigo[7] = PWM2[0];
        codigo[8] = PWM2[1];
        
        codigo[10] = PWM3[0];
        codigo[11] = PWM3[1];
        
        codigo[13] = PWM4[0];
        codigo[14] = PWM4[1];
        
        codigo[16] = PWM5[0];
        codigo[17] = PWM5[1];
        
        codigo[19] = PWM6[0];
        codigo[20] = PWM6[1];
        
        codigo[22] = PWM7[0];
        codigo[23] = PWM7[1];
        
        codigo[25] = PWM8[0];
        codigo[26] = PWM8[1];
        
        codigo[28] = PWM9[0];
        codigo[29] = PWM9[1];
        LCD_Position(0,0); 
        LCD_PrintString(codigo);
        UART_PutString(codigo);
        CyDelay(instructions[i][9]);
        }
}