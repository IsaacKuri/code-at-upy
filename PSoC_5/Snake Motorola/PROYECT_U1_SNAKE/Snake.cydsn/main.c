#include "project.h"
#include "stdio.h"
#include "GlobalDef.h"
//#include "PixelEngine.h"
//#include "GlobalFunc.h"
#include "SnakeGame.h"
//Global Variables

struct player{
    char name[5];
    int score;
};

struct player players[4];

char cur_name[5] = "isaac";

int SnakeBoard[snake_board_height][snake_board_length] = {
    {0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
    {0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0}
};

//-----------Comm Handler-----------------
char codigo[32] = "NNN,0,0,F";
char check[32] = "000000000";
char foo;
int cs = 0;
int pass = 1;
int comas = 0;
int read = 1;
char com_state = 'm';
int max_comas = 0;
//Flags
int name_wait = 0;
int pause_status = 0;
//Counters
int time_paused = 0;
int period_offs_old = 0;
//Function Prototypes
void Animation();
void UpdateStatus();
//EEPROM Functions
void EepromFirstInit();
void PlaceHolders();
void WriteNewScores();
void ReadScores();
bool UpdateFirstPlace();

CY_ISR_PROTO(com_handler);

CY_ISR_PROTO(pause_handler);
CY_ISR_PROTO(resume_handler);
CY_ISR_PROTO(real_handler);
CY_ISR_PROTO(tic_handler);
char state = 'h';
int main(void)
{
    CyGlobalIntEnable; 
    //Inits of the modules
    EEPROM_Start();
    LCD_Start();
    Timer_Seed_Start();
    UART_Start();
    //ISR
    com_StartEx(com_handler);
    isr_PAUSE_StartEx(pause_handler);
    isr_RESUME_StartEx(resume_handler);
    isr_REAL_StartEx(real_handler);
    isr_TIC_StartEx(tic_handler);
    //Randomizations
    srand(Timer_Seed_ReadCounter());
    Timer_Seed_Stop();
    
    
    for(;;)
    {
        switch(state){
            case 'h':
                //EepromFirstInit();
                ReadScores();
                int flag = 0;
                for(int i = 0; i < 5; i++){
                    if(players[0].name[i] == 0){
                        flag = 1;
                        break;
                    }
                }
                if(flag == 1){
                    EepromFirstInit();
                }
                state = 's';
                break;
            case 's':
                //Start State
                LCD_ClearDisplay();
                Start_Snake(SnakeBoard);
                LCD_Position(0,0);
                LCD_PrintString("Waiting For");
                LCD_Position(1,0);
                LCD_PrintString("Names To Start");
                
                //Get in a loop to accept cur player name.
                while(name_wait == 0){CyDelay(5);}
                
                //Start timer to cicle the Snake
                Animation();
                Timer_Tic_Start();
                Timer_Tic_WritePeriod(1000);
                
                state = 'g';
                UpdateStatus();
                break;
            case 'p':
                //Pause State
                Timer_Tic_Sleep();
                Animation();
                Timer_Real_Start();
                time_paused = 0;
                period_offs_old = 0;
                while(pause_status == 1){
                    if(time_paused == 15){
                        LCD_Position(0,4);
                        LCD_PrintString("SLEEP");
                        CyDelay(250);
                        LCD_Sleep();
                        UART_Sleep();
                        //Timer_Tic_Sleep();
                        CyPmSaveClocks();
                        CyPmHibernate();
                        CyPmRestoreClocks();
                        UART_Wakeup();
                        LCD_Wakeup();
                        time_paused = 0;
                        state = 'g';
                        Timer_Tic_Wakeup();
                        break;
                    }
                    LCD_Position(0,4);
                    LCD_PrintString("PAUSED");
                    CyDelay(150);
                    LCD_ClearDisplay();
                    CyDelay(150);
                }
                Timer_Real_Stop();
                Animation();
                Timer_Tic_Wakeup();
                state = 'g';
                UpdateStatus();
                break;
            case 'g':
                //Game is Ocurring so nothing has to happen.
                break;
             case 'e':
                //RIP Dialog
                Animation();
                LCD_Position(0,3);
                LCD_PrintString("Game Over");
                LCD_Position(1,0);
                LCD_PrintString(cur_name);
                LCD_Position(1,6);
                LCD_PrintString("SC:");
                LCD_Position(1,9);
                LCD_PrintNumber(match_score);
                CyDelay(50);
                state = 'c';
                UpdateStatus();
                break;
            case 'm':
                //Achieven the max score
                Animation();
                LCD_Position(0,0);
                LCD_PrintString("Max Score Achived!");
                CyDelay(50);
                state = 'c';
                UpdateStatus();
                break;
            case 'c':
                //Add Max Scoes Wait a bit and reset
                if(UpdateFirstPlace()){
                    WriteNewScores();
                    ReadScores();
                }
                for(int i = 0; i < 3; i++){
                LCD_ClearDisplay();
                LCD_Position(0,0);
                if(i == 0){LCD_PrintString("First Place:");}
                if(i == 1){LCD_PrintString("Second Place:");}
                if(i == 2){LCD_PrintString("Third Place:");}
                LCD_Position(1,0);
                LCD_PrintString(players[i].name);
                LCD_Position(1,6);
                LCD_PrintString("SC:");
                LCD_Position(1,9);
                LCD_PrintNumber(players[i].score);
                CyDelay(2000);
                }
                state = 's';
                name_wait = 0;
                UpdateStatus();
                break;
        }
    }
}

//Eeprom functionality
void EepromFirstInit(){
    PlaceHolders();
    //First Write to EEPROM
    for(int i = 0; i < 3; i++){
        EEPROM_WriteByte(players[i].score, 0 + i*6);
        for(int j = 1; j < 6; j++){
            EEPROM_WriteByte(players[i].name[j - 1], j + i*6);
        }
    }
}
void PlaceHolders(){
        for(int i = 0; i < 3; i++){
        players[i].score = 0;
        for(int j = 1; j < 6; j++){
            players[i].name[j - 1] = '#';
        }
    }
}
void WriteNewScores(){
    for(int i = 0; i < 3; i++){
        EEPROM_WriteByte(players[i].score, 0 + i*6);
        for(int j = 1; j < 6; j++){
            EEPROM_WriteByte(players[i].name[j - 1], j + i*6);
        }
    }
}
void ReadScores(){
    for(int i = 0; i < 3; i++){
        players[i].score = EEPROM_ReadByte(0 + i*6);
        for(int j = 1; j < 6; j++){
            players[i].name[j - 1] = EEPROM_ReadByte(j + i*6);
        }
    }
}
bool UpdateFirstPlace(){
    int target = -1;
    struct player players_temp;
    
    for(int i = 0; i < 3; i++){
        if(match_score > players[i].score){
            target = i;
            break;
        }
    }
    
    if (target != -1){
        players[3].score = match_score;
        for(int i = 0; i < 5; i++){
        players[3].name[i] = cur_name[i];
        }
        //Bubble sorting
        for (int c = 0 ; c < 4 - 1; c++) {
            for (int d = 0 ; d < 4 - c - 1; d++){
             if (players[d].score < players[d+1].score){
                players_temp = players[d];
                players[d]   = players[d+1];
                players[d+1] = players_temp;
                }
            }
        }
        return true;
    }
    return false;
}
//Animation for transitions.
void Animation(){
    for(int i = 0; i < 8; i++){
        LCD_Position(0,8 + i);
        LCD_PutChar('#');
        LCD_Position(0,7 - i);
        LCD_PutChar('#');
        LCD_Position(1,8 + i);
        LCD_PutChar('#');
        LCD_Position(1,7 - i);
        LCD_PutChar('#');
        CyDelay(100);
    }
    LCD_ClearDisplay();
    for(int i = 0; i < 16; i++){
        LCD_Position(0,i);
        LCD_PutChar('%');
        LCD_Position(1,i);
        LCD_PutChar('%');
    }
    CyDelay(100);
    LCD_ClearDisplay();
}

//Interruption rutines
CY_ISR(pause_handler){
    CyDelay(50);
    if(state == 'g'){
    state = 'p';
    pause_status = 1;
    }
    Pause_ClearInterrupt();
    isr_PAUSE_ClearPending();
}

CY_ISR(resume_handler){
    if(pause_status == 1){
        pause_status = 0;
    }
    Resume_ClearInterrupt();
    isr_RESUME_ClearPending();
}
CY_ISR(tic_handler){
    switch(state){
        case 'g':
        if(RandNum(0,100) < 10){
                        add_bait();
                    }
                    bool good_move = move_snake();
                    if (!good_move){
                        draw_snake();    
                    }
                    else {
                        state = 'e';
                        UpdateStatus();
                    }
                    if(match_score == max_score){
                        state = 'm';
                        UpdateStatus();
                    }
            break;
    }
    if(period_offs_old != period_offs){
    int res = 1000/(2*period_offs);
    //int res = 1000 - 100*period_offs;
    Timer_Tic_WritePeriod(res);
    }
    period_offs_old = period_offs;
    Timer_Tic_ReadStatusRegister();
    isr_TIC_ClearPending();
}
CY_ISR(real_handler){
    if(time_paused < 15){
    time_paused++;
    }
    Timer_Real_ReadStatusRegister();
    isr_REAL_ClearPending();
}


//Recibir Nombre
void Names_Recieved(char name_str[32]){
    int j = 0;
    for(int i = 4; i < 9; i++){
        cur_name[j] = name_str[i];
        j++;
    }
    name_wait = 1;
}
//Update Status
void UpdateStatus(){
    char mesage[24];
    sprintf(mesage,"BST,%c,F\n",state);
    UART_PutString(mesage);
}

//------Comunicacion UART----
CY_ISR(com_handler){
    foo = UART_GetChar();
    if(foo == 'M'){
        cs = 0;
        pass = 1;
        comas = 0;
        read = 1;
        max_comas = 2;
        com_state = 'm';
    }
    else if(foo == 'J'){
        cs = 0;
        pass = 1;
        comas = 0;
        read = 1;
        max_comas = 3;
        com_state = 'n';
    }
    switch(com_state){
        case 'm':
            if(foo == ','){
                comas++;
            }
            if(read == 1){
             check[cs] = foo;
            }
            if(cs == 3){
                if(check[0] != 'M'){ pass = 0;}
                if(check[1] != 'V'){ pass = 0;}
                if(check[2] != 'T'){ pass = 0;}
            }
            if(cs == 6){
                if(check[0] != 'M'){ pass = 0;}
                if(check[1] != 'V'){ pass = 0;}
                if(check[2] != 'T'){ pass = 0;}
            }
            if((foo == 'F')&&(cs==6)&&(pass == 1)&&(comas == max_comas)){
                 read = 0;
                for(int i = 0; i < 7; i++){
                    codigo[i] = check[i];
                }
                change_dir(codigo[4]);
                com_state = 'x';
            }
            cs++;
            break;
            case 'n':
                if(foo == ','){
                    comas++;
                }
                if(read == 1){
                 check[cs] = foo;
                }
                if(cs == 3){
                    if(check[0] != 'J'){ pass = 0;}
                    if(check[1] != 'K'){ pass = 0;}
                    if(check[2] != 'L'){ pass = 0;}
                }
                if(cs == 17){
                    if(check[0] != 'J'){ pass = 0;}
                    if(check[1] != 'K'){ pass = 0;}
                    if(check[2] != 'L'){ pass = 0;}
                }
                if((foo == 'F')&&(cs==16)&&(pass == 1)&&(comas == max_comas)){
                     read = 0;
                    for(int i = 0; i < 17; i++){
                        codigo[i] = check[i];
                    }
                    Names_Recieved(codigo);
                    com_state = 'x';
                }
                cs++;
                break;
            default:
                break;
        }
   
    com_ClearPending();
}