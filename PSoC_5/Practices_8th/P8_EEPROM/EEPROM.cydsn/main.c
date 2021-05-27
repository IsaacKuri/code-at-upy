#include "project.h"
#include "stdio.h"

char val[2];
char val_r[2];
char msg[40];
char state = 'f';
char ins_1 = 'n';

int sum;

CY_ISR_PROTO(UART_handler);
CY_ISR_PROTO(RESET_handler);
CY_ISR_PROTO(RESTART_handler);
int ChartoInt(char t_);
int main(void)
{
    CyGlobalIntEnable;
    UART_Start();
    EEPROM_Start();
    isr_UART_StartEx(UART_handler);
    isr_RESET_StartEx(RESET_handler);
    isr_RESTART_StartEx(RESTART_handler);
    for(;;)
    {
        switch(state){
            case 'f':
                val_r[0] = EEPROM_ReadByte(0);
                if(val_r[0] != 'n'){
                        state = 'i';
                }
                else{
                EEPROM_WriteByte(ins_1, 0);
                EEPROM_WriteByte(ins_1, 1);
                state = 'i';
                }
                break;
            case 'i':
                val_r[0] = EEPROM_ReadByte(0);
                val_r[1] = EEPROM_ReadByte(1);
                if(val_r[0] != 'n'){
                    state = 'a';
                }
                else {
                    UART_PutString("Plase input your first value \n");
                    state = 'b';
                }
                break;
            case 'a':
                if(val_r[1] != 'n'){
                    state = 's';
                }
                else {
                    UART_PutString("Plase input your second value \n");
                    state = 'c';
                }
                break;
            case 'b':
                if(val_r[0] != 'n'){
                    state = 'a';
                }
                break;
            case 'c':
                if(val_r[1] != 'n'){
                    state = 's';
                }
                break;
            case 's':
                    sum = ChartoInt(val_r[0]) + ChartoInt(val_r[1]);
                    sprintf(msg, "Your sum is %d \n", sum);
                    UART_PutString(msg);
                    state = 'p';
                break;
            case 'p':
                break;
        }
    }
}

CY_ISR(UART_handler){
    switch(state){
        case 'b':
            val[0] = UART_GetChar();
            EEPROM_WriteByte(val[0], 0);
            val_r[0] = EEPROM_ReadByte(0);
            break;
        case 'c':
            val[1] = UART_GetChar();
            EEPROM_WriteByte(val[1], 1);
            val_r[1] = EEPROM_ReadByte(1);
            break;
        default:
            break;
    }
    isr_UART_ClearPending();
}
CY_ISR(RESET_handler){
    state = 's';
    BTN_1_ClearInterrupt();
    isr_RESET_ClearPending();
    CyDelay(50);
    CySoftwareReset();
};
CY_ISR(RESTART_handler){
    EEPROM_WriteByte(ins_1, 0);
    EEPROM_WriteByte(ins_1, 1);
    state = 'i';
    BTN_2_ClearInterrupt();
    isr_RESTART_ClearPending();
};
int ChartoInt(char t_){
    return t_ - '0';
};
