#include "project.h"
uint16 reg = 0;
int main(void)
{
    CyGlobalIntEnable; 
    PWM_Start();

    for(;;)
    {
        if(reg == 4){
            reg = 0;
        }
        Control_Reg_1_Write(reg);
         reg++;
        CyDelay(1000);
    }
}

/* [] END OF FILE */
