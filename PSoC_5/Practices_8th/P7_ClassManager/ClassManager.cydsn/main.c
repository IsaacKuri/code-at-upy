#include "project.h"
#include "stdio.h"

uint8 ArrBuffer[1];
char msg[64];

int students = 0;
int ontime = 1;
char state = 'i';
CY_ISR_PROTO(timer_isr_handler);
CY_ISR_PROTO(count_handler);
int main(void){

    CyGlobalIntEnable; 
    //Global Configs
    UART_Start();
    I2C_Start();
    I2C_SlaveInitWriteBuf(ArrBuffer,1);
    //Interrupt Handling
    time_isr_StartEx(timer_isr_handler);
    time_isr_ClearPending();
    
    counting_StartEx(count_handler);
    counting_ClearPending();
    BTN_ClearInterrupt();
    for(;;)
    {
        switch(state){
            case 'i':
                //Preparing I2C for sleep
                I2C_Sleep();
                UART_Start();
                UART_PutString("Waiting to Init \n");
                CyDelay(100);
                //Entering sleep, leaving flag to be woken up.
                CyPmSaveClocks();
                CyPmSleep(PM_SLEEP_TIME_NONE, PM_SLEEP_SRC_I2C);
                CyPmRestoreClocks();
                //Process after being woken up
                ListC_Write(0);
                I2C_Wakeup();
                UART_Start();
                UART_PutString("Ready to Count \n");
                
                Timer_Start();
                state = 's';
                break;
            case 's':
                if(students >= 15){
                    state = 'i';
                    Timer_Stop();
                    LED_0_Write(1);
                    ListC_Write(1);
                    UART_PutString("All Students Here \n");
                    CyDelay(500);
                    LED_0_Write(0);
                    students = 0;
                }
                break;
            case 'h':
                I2C_Sleep();
                //Entering Hibernate 
                CyPmSaveClocks();
                CyPmHibernate();
                CyPmRestoreClocks();
                //Exiting Hibernate
                I2C_Wakeup();
                UART_Start();
                sprintf(msg, "%d Student Arrived Late \n", students);
                UART_PutString(msg);
                CyDelay(50);
                
                if(students >= 15){
                    state = 'i';
                    LED_0_Write(1);
                    ListC_Write(1);
                    UART_Start();
                    UART_PutString("All Students Here \n");
                    CyDelay(500);
                    LED_0_Write(0);
                    students = 0; 
                }
                break;
        }
    }
}
CY_ISR(timer_isr_handler){
    if(students < 15){
        state = 'h';
        UART_PutString("Entering Hiberante Mode \n");
        CyDelay(100);
    }
    Timer_Stop();
    Timer_ReadStatusRegister();
    time_isr_ClearPending();
}

CY_ISR(count_handler){
    switch(state){
        case 's':
            CyDelayUs(40);
            students++;
            sprintf(msg, "%d Students Have Arrived \n", students);
            UART_PutString(msg);
            break;
        case 'h':
            //CyDelayUs(40);
            students++;
            LED_1_Write(1);
            CyDelay(100);
            LED_1_Write(0);
            break;
    }
    counting_ClearPending();
    BTN_ClearInterrupt();
}