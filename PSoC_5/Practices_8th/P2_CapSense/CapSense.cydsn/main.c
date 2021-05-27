#include "project.h"
#include "stdio.h"

int pos_bar = 0;
int pos_mun = 0;
int relpos = 7;
int rebote = 0;
int old_pos = 0;
uint16 sen_old = 0;
uint16 sen_old_old = 0;
int SensorOldTest;
int SensorInt;
int SensorOldInt;
int main(void)
{
    uint16 Sensor;
    uint16 SensorOld = 0xFFFF;
    char msg[50];
    CyGlobalIntEnable;

    UART_Start();
    CapSense_Start();
    LCD_Start();

    CapSense_InitializeAllBaselines();
    CapSense_ScanEnabledWidgets();

    for (;;)
    {
        LCD_ClearDisplay();
        if (!CapSense_IsBusy())
        {
            SensorOldTest = Sensor;
            Sensor = CapSense_GetCentroidPos(CapSense_LINEARSLIDER0__LS);
            if (Sensor != 0xFFFF && Sensor != SensorOld)
            {
                sprintf(msg, "Sensor: %d, %d, %d, %d, %d\r\n", Sensor,SensorOld,old_pos,pos_mun,pos_bar);
                UART_PutString(msg);
                SensorOld = Sensor;
            }
            CapSense_UpdateEnabledBaselines();
            CapSense_ScanEnabledWidgets();
        }
        SensorInt = Sensor;
        SensorOldInt = SensorOldTest;
        if (SensorOld != 0xFFFF)
        {
           if ((sen_old != Sensor) &&(sen_old_old != SensorOldTest)){
                UART_PutString("Here\n");
                if (SensorInt < SensorOldInt)
                {
                    UART_PutString("Right\n");
                    if (pos_bar != -7)
                    {
                        pos_bar--;
                    }
                    if (pos_mun != 0)
                    {
                        pos_mun--;
                    }
                }
                else if (SensorInt > SensorOldInt)
                {
                    UART_PutString("Left\n");
                    if (pos_bar != 7)
                    {
                        pos_bar++;
                    }
                    if (pos_mun != 15)
                    {
                        pos_mun++;
                    }
                }
            }
            if (relpos < 0)
            {
                relpos = pos_bar * -1;
            }
            else
            {
                relpos = pos_bar;
            }
            LCD_Position(0, 7);
            LCD_PutChar(LCD_CUSTOM_0);
            LCD_Position(0, 8);
            LCD_PutChar(LCD_CUSTOM_0);
            for (int i = 0; i <= relpos; i++)
            {
                if (pos_bar == 0)
                {
                    LCD_Position(0, 8);
                }
                if (pos_bar < 0)
                {
                    LCD_Position(0, 7 - i);
                }
                else if (pos_bar > 0)
                {
                    LCD_Position(0, 8 + i);
                }
                LCD_PutChar(LCD_CUSTOM_0);
            }
            //Imprimir muñeco

            LCD_Position(1, pos_mun);
            if (rebote == 0)
            {
                LCD_PutChar(LCD_CUSTOM_1);
                rebote = 1;
            }
            else if (rebote == 1)
            {
                LCD_PutChar(LCD_CUSTOM_2);
                rebote = 0;
            }
            CyDelay(5);
        }
        sen_old = Sensor;
        sen_old_old = SensorOldTest;
    }
}