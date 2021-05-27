#include "project.h"

int main(void)
{
    CyGlobalIntEnable; 
    CapSense_Start();
    CapSense_InitializeAllBaselines();
    
    for(;;)
    {
        CapSense_ScanEnabledWidgets();
        CapSense_EnableWidget(CapSense_PROXIMITYSENSOR0__PROX);
     if (!CapSense_IsBusy())
        {
            LED_Write(!CapSense_CheckIsWidgetActive(CapSense_PROXIMITYSENSOR0__PROX));
        }  
        CapSense_UpdateEnabledBaselines();
    }
}

/* [] END OF FILE */
