#include "project.h"
//---General Uses----
int wait_between = 2000;
//-----------Comm Handler-----------------
char codigo[32] = "NNN,0,0,F";
char check[32] = "000000000";
char foo;
int cs = 0;
int pass = 1;
int comas = 0;
int read = 1;
char com_state = 'n';
int max_comas = 0;
CY_ISR_PROTO(com_handler);
//-----------Data Structure------------------
//Game State
int name_wait = 0;
char state = 's';
char game_state = 'p';
int player = 1;
    /*
    Start = s
    Game = g
        Placements
            P1 = 1
            P2 = 2
        Battle
            P1 = 1
            P2 = 2
    End = e
    */
//Cursor Placement
int cur_x = 0;
int cur_y = 0;

int coor_x = 0;
int coor_y = 0;
//Winner
char winner[5] = "O";
//Player 1
char p1_name[5] = "Juan";
int p1_ships = 3;
int p1_ships_cur = 3;
int p1_ammo = 3;
int p1_death_ships = 0;
int p1_s1_pos[2] = {0,0};
int p1_s2_heatlh = 2;
int p1_s2_pos[2][2] = {{0,0},{0,1}};
int p1_s3_heatlh = 2;
int p1_s3_pos[2][2] = {{0,0},{1,0}};
int p1_shoot_board[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int p1_shoot_board_temp[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int p1_ship_board[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int p1_ship_board_temp[32];

//Player 2
char p2_name[5] = "Jose";
int p2_ships = 3;
int p2_ships_cur = 3;
int p2_ammo = 3;
int p2_death_ships = 0;
int p2_s1_pos[2] = {0,0};
int p2_s2_pos[2][2] = {{0,0},{0,1}};
int p2_s3_pos[2][2] = {{0,0},{1,0}};
int p2_shoot_board[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int p2_shoot_board_temp[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int p2_ship_board[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int p2_ship_board_temp[32];

//-----------Function Constructor------------
void Engine_Handler(int screen[32]);
void Custom_Char(int c_char);
int Pos_2D(int posx, int posy);
void Mov_Cur(char mov_str[32]);
int HextoInt(char a);
void Upt_Coor(char upt_str[32]);
void UpdateStatus();

int main(void)
{
    CyGlobalIntEnable;
    LCD_Start();
    UART_Start();
    com_StartEx(com_handler);
    com_ClearPending();
    //----Debug Area----
    state = 's';
    //----EO Debug Area----
    for(;;)
    {
    LCD_ClearDisplay();
   switch(state){
        case 'd':
            LCD_Position(0,0);
            LCD_PrintString(codigo);
            LCD_Position(1,0);
            LCD_PrintNumber(coor_x);
            LCD_Position(1,10);
            LCD_PrintNumber(coor_y);
            //LCD_Position(0,10);
           // LCD_PrintNumber(cur_x);
           // LCD_Position(1,10);
           // LCD_PrintNumber(cur_y);
            CyDelay(5);
            break;
        case 's':
            LCD_Position(0,0);
            LCD_PrintString("Waiting For");
            LCD_Position(1,0);
            LCD_PrintString("Names To Start");
            while(name_wait == 0){CyDelay(5);}
            state = 'g';
            UpdateStatus();
            break;
        case 'g':
            switch(game_state){
                //Placements
                case 'p':
                    switch(player){
                        case 1:
                            for(;;){
                                LCD_ClearDisplay();
                                LCD_Position(0,0);
                                LCD_PrintString("Place your Ships");
                                LCD_Position(1,0);
                                LCD_PrintString(p1_name);
                                CyDelay(wait_between);
                                LCD_ClearDisplay();
                                LCD_Position(0,0);
                                LCD_PrintString("Press A");
                                LCD_Position(1,0);
                                LCD_PrintString("to Continue");
                                while(BUT_Read() == 0){
                                    CyDelay(5);
                                };
                                break;
                            }
                            LCD_ClearDisplay();
                            LCD_Position(0,0);
                            LCD_PrintString("Use Arrow Keys");
                            LCD_Position(1,0);
                            LCD_PrintString("To Move");
                            CyDelay(wait_between);
                            LCD_ClearDisplay();
                            LCD_Position(0,0);
                            LCD_PrintString("Press A");
                            LCD_Position(1,0);
                            LCD_PrintString("to Confirm");
                            CyDelay(wait_between);
                            //First Ship Placement
                            for(;;){
                                p1_ship_board_temp[Pos_2D(cur_x,cur_y)] = 1;
                                Engine_Handler(p1_ship_board_temp);
                                
                                if(BUT_Read() == 1){
                                    p1_ship_board[Pos_2D(cur_x,cur_y)] = 1;
                                    break;
                                }
                                for(int i = 0; i < 32; i++){
                                    p1_ship_board_temp[i] = p1_ship_board[i];
                                }
                                CyDelay(10);
                                }
                                for(;;){
                                    p1_ship_board_temp[Pos_2D(cur_x,cur_y)] = 1;
                                    Engine_Handler(p1_ship_board_temp);
                                    
                                    if(BUT_Read() == 1){
                                        p1_s1_pos[0] = cur_x;
                                        p1_s1_pos[1] = cur_y;
                                        for(int i = 0; i < 32; i++){
                                        p1_ship_board[i] = p1_ship_board_temp[i];
                                        }
                                        break;
                                    }
                                    else{
                                        for(int i = 0; i < 32; i++){
                                            p1_ship_board_temp[i] = p1_ship_board[i];
                                        }
                                    }
                                    CyDelay(10);
                                }
                                //EOR
                                LCD_ClearDisplay();
                                LCD_Position(0,0);
                                LCD_PrintString("Place Your");
                                LCD_Position(1,0);
                                LCD_PrintString("Second Ship");
                                CyDelay(wait_between);
                            
                                //Second Ship Placement
                                int able_to_place_1 = 0;
                                int able_to_place_2 = 0;
                                cur_x = 0;
                                cur_y = 0;
                                for(;;){
                                    if(p1_ship_board[Pos_2D(cur_x,0)] == 1){
                                    p1_ship_board_temp[Pos_2D(cur_x,0)] = 4;
                                    able_to_place_1 = 0;
                                    }
                                    else{
                                    p1_ship_board_temp[Pos_2D(cur_x,0)] = 1;
                                    able_to_place_1 = 1;
                                    }
                                    if(p1_ship_board[Pos_2D(cur_x,1)] == 1){
                                    p1_ship_board_temp[Pos_2D(cur_x,1)] = 4;
                                    able_to_place_2 = 0;
                                    }
                                    else{
                                    p1_ship_board_temp[Pos_2D(cur_x,1)] = 1;
                                    able_to_place_2 = 1;
                                    }
                                    Engine_Handler(p1_ship_board_temp);
                                    
                                    if((BUT_Read() == 1)&&(able_to_place_1 == 1)&&(able_to_place_2)){
                                        p1_ship_board[Pos_2D(cur_x,0)] = 1;
                                        p1_ship_board[Pos_2D(cur_x,1)] = 1;
                                        p1_s2_pos[0][0] = cur_x;
                                        p1_s2_pos[0][1] = 0;
                                        p1_s2_pos[1][0] = cur_x;
                                        p1_s2_pos[1][1] = 1;
                                        break;
                                    }
                                    for(int i = 0; i < 32; i++){
                                        p1_ship_board_temp[i] = p1_ship_board[i];
                                    }
                                    CyDelay(10);
                                }
                                //EOR
                                LCD_ClearDisplay();
                                LCD_Position(0,0);
                                LCD_PrintString("Place Your");
                                LCD_Position(1,0);
                                LCD_PrintString("Third Ship");
                                CyDelay(wait_between);
                            
                                //Third Ship Placement
                                able_to_place_1 = 0;
                                able_to_place_2 = 0;
                                cur_x = 0;
                                cur_y = 0;
                                for(;;){
                                    if(cur_x == 15){
                                        cur_x = 14;
                                    }
                                    if(p1_ship_board[Pos_2D(cur_x,cur_y)] == 1){
                                    p1_ship_board_temp[Pos_2D(cur_x,cur_y)] = 4;
                                    able_to_place_1 = 0;
                                    }
                                    else{
                                    p1_ship_board_temp[Pos_2D(cur_x,cur_y)] = 1;
                                    able_to_place_1 = 1;
                                    }
                                    if(p1_ship_board[Pos_2D(cur_x + 1,cur_y)] == 1){
                                    p1_ship_board_temp[Pos_2D(cur_x + 1,cur_y)] = 4;
                                    able_to_place_2 = 0;
                                    }
                                    else{
                                    p1_ship_board_temp[Pos_2D(cur_x + 1,cur_y)] = 1;
                                    able_to_place_2 = 1;
                                    }
                                    Engine_Handler(p1_ship_board_temp);
                                    
                                    if((BUT_Read() == 1)&&(able_to_place_1 == 1)&&(able_to_place_2)){
                                        p1_ship_board[Pos_2D(cur_x,cur_y)] = 1;
                                        p1_ship_board[Pos_2D(cur_x + 1,cur_y)] = 1;
                                        p1_s3_pos[0][0] = cur_x;
                                        p1_s3_pos[0][1] = cur_y;
                                        p1_s3_pos[1][0] = cur_x + 1;
                                        p1_s3_pos[1][1] = cur_y;
                                        break;
                                    }
                                    for(int i = 0; i < 32; i++){
                                        p1_ship_board_temp[i] = p1_ship_board[i];
                                    }
                                    CyDelay(10);
                                }
                                //EOR
                                //Final Placement Shown to User
                                LCD_ClearDisplay();
                                LCD_Position(0,0);
                                LCD_PrintString("Take A Look To");
                                LCD_Position(1,0);
                                LCD_PrintString("Your Ships");
                                CyDelay(wait_between);
                                Engine_Handler(p1_ship_board);
                                CyDelay(wait_between);
                                player = 2;
                                cur_x = 0;
                                cur_y = 0;
                                UpdateStatus();
                                break;
                                //EOR
                        //Same routine for player 2
                        case 2:
                                for(;;){
                                LCD_ClearDisplay();
                                LCD_Position(0,0);
                                LCD_PrintString("Place your Ships");
                                LCD_Position(1,0);
                                LCD_PrintString(p2_name);
                                CyDelay(wait_between);
                                LCD_ClearDisplay();
                                LCD_Position(0,0);
                                LCD_PrintString("Press A");
                                LCD_Position(1,0);
                                LCD_PrintString("to Continue");
                                while(BUT_Read() == 0){
                                    CyDelay(5);
                                };
                                break;
                                }
                                LCD_ClearDisplay();
                                LCD_Position(0,0);
                                LCD_PrintString("Use Arrow Keys");
                                LCD_Position(1,0);
                                LCD_PrintString("To Move");
                                CyDelay(wait_between);
                                LCD_ClearDisplay();
                                LCD_Position(0,0);
                                LCD_PrintString("Press A");
                                LCD_Position(1,0);
                                LCD_PrintString("to Confirm");
                                CyDelay(wait_between);
                                //First Ship Placement
                                for(;;){
                                    p2_ship_board_temp[Pos_2D(cur_x,cur_y)] = 1;
                                    Engine_Handler(p2_ship_board_temp);
                                    
                                    if(BUT_Read() == 1){
                                        p2_ship_board[Pos_2D(cur_x,cur_y)] = 1;
                                        break;
                                    }
                                    for(int i = 0; i < 32; i++){
                                        p2_ship_board_temp[i] = p2_ship_board[i];
                                    }
                                    CyDelay(10);
                                    }
                                    for(;;){
                                        p2_ship_board_temp[Pos_2D(cur_x,cur_y)] = 1;
                                        Engine_Handler(p2_ship_board_temp);
                                        
                                        if(BUT_Read() == 1){
                                            p2_s1_pos[0] = cur_x;
                                            p2_s1_pos[1] = cur_y;
                                            for(int i = 0; i < 32; i++){
                                            p2_ship_board[i] = p2_ship_board_temp[i];
                                            }
                                            break;
                                        }
                                        else{
                                            for(int i = 0; i < 32; i++){
                                                p2_ship_board_temp[i] = p2_ship_board[i];
                                            }
                                        }
                                        CyDelay(10);
                                    }
                                    //EOR
                                    LCD_ClearDisplay();
                                    LCD_Position(0,0);
                                    LCD_PrintString("Place Your");
                                    LCD_Position(1,0);
                                    LCD_PrintString("Second Ship");
                                    CyDelay(wait_between);
                                
                                    //Second Ship Placement
                                    int x_able_to_place_1 = 0;
                                    int x_able_to_place_2 = 0;
                                    cur_x = 0;
                                    cur_y = 0;
                                    for(;;){
                                        if(p2_ship_board[Pos_2D(cur_x,0)] == 1){
                                        p2_ship_board_temp[Pos_2D(cur_x,0)] = 4;
                                        x_able_to_place_1 = 0;
                                        }
                                        else{
                                        p2_ship_board_temp[Pos_2D(cur_x,0)] = 1;
                                        x_able_to_place_1 = 1;
                                        }
                                        if(p2_ship_board[Pos_2D(cur_x,1)] == 1){
                                        p2_ship_board_temp[Pos_2D(cur_x,1)] = 4;
                                        x_able_to_place_2 = 0;
                                        }
                                        else{
                                        p2_ship_board_temp[Pos_2D(cur_x,1)] = 1;
                                        x_able_to_place_2 = 1;
                                        }
                                        Engine_Handler(p2_ship_board_temp);
                                        
                                        if((BUT_Read() == 1)&&(x_able_to_place_1 == 1)&&(x_able_to_place_2)){
                                            p2_ship_board[Pos_2D(cur_x,0)] = 1;
                                            p2_ship_board[Pos_2D(cur_x,1)] = 1;
                                            p2_s2_pos[0][0] = cur_x;
                                            p2_s2_pos[0][1] = 0;
                                            p2_s2_pos[1][0] = cur_x;
                                            p2_s2_pos[1][1] = 1;
                                            break;
                                        }
                                        for(int i = 0; i < 32; i++){
                                            p2_ship_board_temp[i] = p2_ship_board[i];
                                        }
                                        CyDelay(10);
                                    }
                                    //EOR
                                    LCD_ClearDisplay();
                                    LCD_Position(0,0);
                                    LCD_PrintString("Place Your");
                                    LCD_Position(1,0);
                                    LCD_PrintString("Third Ship");
                                    CyDelay(wait_between);
                                
                                    //Third Ship Placement
                                    x_able_to_place_1 = 0;
                                    x_able_to_place_2 = 0;
                                    cur_x = 0;
                                    cur_y = 0;
                                    for(;;){
                                        if(cur_x == 15){
                                            cur_x = 14;
                                        }
                                        if(p2_ship_board[Pos_2D(cur_x,cur_y)] == 1){
                                        p2_ship_board_temp[Pos_2D(cur_x,cur_y)] = 4;
                                        x_able_to_place_1 = 0;
                                        }
                                        else{
                                        p2_ship_board_temp[Pos_2D(cur_x,cur_y)] = 1;
                                        x_able_to_place_1 = 1;
                                        }
                                        if(p2_ship_board[Pos_2D(cur_x + 1,cur_y)] == 1){
                                        p2_ship_board_temp[Pos_2D(cur_x + 1,cur_y)] = 4;
                                        x_able_to_place_2 = 0;
                                        }
                                        else{
                                        p2_ship_board_temp[Pos_2D(cur_x + 1,cur_y)] = 1;
                                        x_able_to_place_2 = 1;
                                        }
                                        Engine_Handler(p2_ship_board_temp);
                                        
                                        if((BUT_Read() == 1)&&(x_able_to_place_1 == 1)&&(x_able_to_place_2)){
                                            p2_ship_board[Pos_2D(cur_x,cur_y)] = 1;
                                            p2_ship_board[Pos_2D(cur_x + 1,cur_y)] = 1;
                                            p2_s3_pos[0][0] = cur_x;
                                            p2_s3_pos[0][1] = cur_y;
                                            p2_s3_pos[1][0] = cur_x + 1;
                                            p2_s3_pos[1][1] = cur_y;
                                            break;
                                        }
                                        for(int i = 0; i < 32; i++){
                                            p2_ship_board_temp[i] = p2_ship_board[i];
                                        }
                                        CyDelay(10);
                                    }
                                    //EOR
                                    //Final Placement Shown to User
                                    LCD_ClearDisplay();
                                    LCD_Position(0,0);
                                    LCD_PrintString("Take A Look To");
                                    LCD_Position(1,0);
                                    LCD_PrintString("Your Ships");
                                    CyDelay(wait_between);
                                    Engine_Handler(p2_ship_board);
                                    CyDelay(wait_between);
                                    player = 1;
                                    game_state = 'd';
                                    UpdateStatus();
                                    break;
                                    //EOR
                    }
                    break;
                //
                case 'd':
                    switch(player){
                        case 1:
                            //Update Player Ships
                            p1_death_ships = 0;
                            if(p1_ship_board[Pos_2D(p1_s1_pos[0],p1_s1_pos[1])] == 4){
                                p1_death_ships++;
                            }
                            if((p1_ship_board[Pos_2D(p1_s2_pos[0][0],p1_s2_pos[1][1])] == 4)&&(p1_ship_board[Pos_2D(p1_s2_pos[1][0],p1_s2_pos[1][1])] == 4)){
                                p1_death_ships++;
                            }
                            if((p1_ship_board[Pos_2D(p1_s3_pos[0][0],p1_s3_pos[0][1])] == 4)&&(p1_ship_board[Pos_2D(p1_s3_pos[1][0],p1_s3_pos[1][1])] == 4)){
                                p1_death_ships++;
                            }
                            //Update Player Ammo
                            p1_ammo = p1_ships - p1_death_ships;
                            p1_ships_cur = p1_ammo;
                            if(p1_ammo == 0){
                                for(int i = 0; i < 5; i++){
                                 winner[i] = p2_name[i];
                                }
                                state = 'e';
                                UpdateStatus();
                                break;
                            }
                            //Update Status
                            UpdateStatus();
                            LCD_Position(0,0);
                            LCD_PrintString(p1_name);
                            LCD_Position(1,0);
                            LCD_PrintString("Your Turn");
                            CyDelay(wait_between);
                            LCD_ClearDisplay();
                            LCD_Position(0,0);
                            LCD_PrintString("To Continue");
                            LCD_Position(1,0);
                            LCD_PrintString("Press A");
                            while(BUT_Read() == 0){CyDelay(5);}
                            LCD_ClearDisplay();
                            LCD_Position(0,0);
                            LCD_PrintString("Your Board");
                            CyDelay(wait_between);
                            Engine_Handler(p1_ship_board);
                            CyDelay(wait_between);
                            LCD_ClearDisplay();
                            LCD_Position(0,0);
                            LCD_PrintString("Place a Bomb");
                            LCD_Position(1,0);
                            LCD_PrintString("Conf. With A");
                            CyDelay(wait_between);
                            for(;;){
                                if((p1_shoot_board_temp[Pos_2D(coor_x, coor_y)] == 2) || (p1_shoot_board_temp[Pos_2D(coor_x, coor_y)] == 3)){ 
                                p1_shoot_board_temp[Pos_2D(coor_x, coor_y)] = 5;
                                }
                                else {
                                 p1_shoot_board_temp[Pos_2D(coor_x, coor_y)] = 2;
                                }
                                Engine_Handler(p1_shoot_board_temp);
                                if(BUT_Read() == 1){
                                    if((p1_shoot_board[Pos_2D(coor_x, coor_y)] != 2)&&(p1_shoot_board[Pos_2D(coor_x, coor_y)] != 3)){
                                        if(p2_ship_board[Pos_2D(coor_x,coor_y)] == 1){
                                            p2_ship_board[Pos_2D(coor_x,coor_y)] = 4;
                                            p1_shoot_board[Pos_2D(coor_x,coor_y)] = 3;
                                            p1_ammo--;
                                        }
                                        else {
                                            p1_shoot_board[Pos_2D(coor_x,coor_y)] = 2;
                                            p1_ammo--;
                                        }
                                    }
                                    else{
                                    }
                                    UpdateStatus();
                                }
                                for(int i = 0; i < 32; i++){
                                    p1_shoot_board_temp[i] = p1_shoot_board[i]; 
                                }
                                if(p1_ammo == 0){
                                    player = 2;
                                    UpdateStatus();
                                    break;
                                }
                                CyDelay(10);
                            }
                            break;
                        case 2:
                            //Update Player Ships
                            p2_death_ships = 0;
                            if(p2_ship_board[Pos_2D(p2_s1_pos[0],p2_s1_pos[1])] == 4){
                                p2_death_ships++;
                            }
                            if((p2_ship_board[Pos_2D(p2_s2_pos[0][0],p2_s2_pos[1][1])] == 4)&&(p2_ship_board[Pos_2D(p2_s2_pos[1][0],p2_s2_pos[1][1])] == 4)){
                                p2_death_ships++;
                            }
                            if((p2_ship_board[Pos_2D(p2_s3_pos[0][0],p2_s3_pos[0][1])] == 4)&&(p2_ship_board[Pos_2D(p2_s3_pos[1][0],p2_s3_pos[1][1])] == 4)){
                                p2_death_ships++;
                            }
                            //Update Player Ammo
                            p2_ammo = p2_ships - p2_death_ships;
                            p2_ships_cur = p2_ammo;
                            if(p2_ammo == 0){
                                for(int i = 0; i < 5; i++){
                                 winner[i] = p1_name[i];
                                }
                                state = 'e';
                                UpdateStatus();
                                break;
                            }
                            //Update Status
                            UpdateStatus();
                            LCD_Position(0,0);
                            LCD_PrintString(p2_name);
                            LCD_Position(1,0);
                            LCD_PrintString("Your Turn");
                            CyDelay(wait_between);
                            LCD_ClearDisplay();
                            LCD_Position(0,0);
                            LCD_PrintString("To Continue");
                            LCD_Position(1,0);
                            LCD_PrintString("Press A");
                            while(BUT_Read() == 0){CyDelay(5);}
                            LCD_ClearDisplay();
                            LCD_Position(0,0);
                            LCD_PrintString("Your Board");
                            CyDelay(wait_between);
                            Engine_Handler(p2_ship_board);
                            CyDelay(wait_between);
                            LCD_ClearDisplay();
                            LCD_Position(0,0);
                            LCD_PrintString("Place a Bomb");
                            LCD_Position(1,0);
                            LCD_PrintString("Conf. With A");
                            CyDelay(wait_between);
                            for(;;){
                                if((p2_shoot_board_temp[Pos_2D(coor_x, coor_y)] == 2) || (p2_shoot_board_temp[Pos_2D(coor_x, coor_y)] == 3)){ 
                                p2_shoot_board_temp[Pos_2D(coor_x, coor_y)] = 5;
                                }
                                else {
                                 p2_shoot_board_temp[Pos_2D(coor_x, coor_y)] = 2;
                                }
                                Engine_Handler(p2_shoot_board_temp);
                                if(BUT_Read() == 1){
                                    if((p2_shoot_board[Pos_2D(coor_x, coor_y)] != 2)&&(p2_shoot_board[Pos_2D(coor_x, coor_y)] != 3)){
                                        if(p1_ship_board[Pos_2D(coor_x,coor_y)] == 1){
                                            p1_ship_board[Pos_2D(coor_x,coor_y)] = 4;
                                            p2_shoot_board[Pos_2D(coor_x,coor_y)] = 3;
                                            p2_ammo--;
                                        }
                                        else {
                                            p2_shoot_board[Pos_2D(coor_x,coor_y)] = 2;
                                            p2_ammo--;
                                        }
                                    }
                                    else{
                                    }
                                    UpdateStatus();
                                }
                                for(int i = 0; i < 32; i++){
                                    p2_shoot_board_temp[i] = p2_shoot_board[i]; 
                                }
                                if(p2_ammo == 0){
                                    player = 1;
                                    UpdateStatus();
                                    break;
                                }
                                CyDelay(10);
                            }
                            break;
                    }
                    break;
            }
            break;
        case 'e':
            LCD_ClearDisplay();
            LCD_Position(0,0);
            LCD_PrintString("The Winner Is");
            LCD_Position(1,0);
            LCD_PrintString(winner);
            CyDelay(5);
            break;
    }
    CyDelay(20);
    }
}



//------Player 
void UpdateStatus(){
    char mesage[24];
    sprintf(mesage,"BST,%c,%c,%d,%d,%d,%d,%d,F\n",state,game_state,player,p1_ships_cur,p1_ammo,p2_ships_cur,p2_ammo);
    UART_PutString(mesage);
}

//------Render Functions -----
void Engine_Handler(int screen[32]){
    LCD_ClearDisplay();
    int x_p = 0;
    int y_p = 0;
    for(int i = 0; i < 32; i++){
       LCD_Position(y_p, x_p);
       Custom_Char(screen[i]);
        if(i == 15){
            x_p = 0;
            y_p = 1;
        }
        else{
        x_p++;
        }
    }
}

void Custom_Char(int c_char){
    switch(c_char){
    case 1:
        LCD_PutChar(LCD_CUSTOM_0);
        break;
    case 2:
        LCD_PutChar(LCD_CUSTOM_1);
        break;
    case 3:
        LCD_PutChar(LCD_CUSTOM_2);
        break;
    case 4:
        LCD_PutChar(LCD_CUSTOM_4);
        break;
    case 5:
        LCD_PutChar(LCD_CUSTOM_5);
        break;
    default:
        LCD_PutChar(LCD_CUSTOM_3);
        break;
    }
}
//Converters
int Pos_2D(int posx, int posy){
    int c = 16*posy + posx; 
    return c;
}
int HextoInt(char a){
    if(a == '0'){
        return 0;
    }
    else if(a == '1'){
        return 1;
    }
    else if(a == '2'){
        return 2;
    }
    else if(a == '3'){
        return 3;
    }
    else if(a == '4'){
        return 4;
    }
    else if(a == '5'){
        return 5;
    }
    else if(a == '6'){
        return 6;
    }
    else if(a == '7'){
        return 7;
    }
    else if(a == '8'){
        return 8;
    }
    else if(a == '9'){
        return 9;
    }
    else if(a == 'A'){
        return 10;
    }
    else if(a == 'B'){
        return 11;
    }
    else if(a == 'U'){
        return 12;
    }
    else if(a == 'D'){
        return 13;
    }
    else if(a == 'E'){
        return 14;
    }
    else if(a == 'G'){
        return 15;
    }
    else{
        return 0;
    }
}
//Coordinates Selector
void Upt_Coor(char upt_str[32]){
    coor_x = HextoInt(upt_str[4]);
    coor_y = HextoInt(upt_str[6]);
}
//Names Recieved
void Names_Recieved(char name_str[32]){
    int j = 0;
    int k = 0;
    for(int i = 4; i < 9; i++){
        p1_name[j] = name_str[i];
        j++;
    }
    for(int i = 10; i < 15; i++){
        p2_name[k] = name_str[i];
        k++;
    }
    name_wait = 1;
}
//Move Cursor Function
void Mov_Cur(char mov_str[32]){
    if(mov_str[4] == 'U'){
        if(cur_y == 1){
        cur_y = 0;
        }
    }
    else if(mov_str[4] == 'D'){
        if(cur_y == 0){
        cur_y = 1;
        }
    }
    else if(mov_str[4] == 'L'){
        if(cur_x != 0){
        cur_x--;
        }
    }
    else if(mov_str[4] == 'R'){
        if(cur_x != 15){
        cur_x++;
        }
    }
};
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
    else if(foo == 'C'){
        cs = 0;
        pass = 1;
        comas = 0;
        read = 1;
        max_comas = 3;
        com_state = 'c';
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
                Mov_Cur(codigo);
                com_state = 'x';
            }
            cs++;
            break;
            case 'c':
                if(foo == ','){
                    comas++;
                }
                if(read == 1){
                 check[cs] = foo;
                }
                if(cs == 3){
                    if(check[0] != 'C'){ pass = 0;}
                    if(check[1] != 'O'){ pass = 0;}
                    if(check[2] != 'N'){ pass = 0;}
                }
                if(cs == 8){
                    if(check[0] != 'C'){ pass = 0;}
                    if(check[1] != 'O'){ pass = 0;}
                    if(check[2] != 'N'){ pass = 0;}
                }
                if((foo == 'F')&&(cs==8)&&(pass == 1)&&(comas == max_comas)){
                     read = 0;
                    for(int i = 0; i < 9; i++){
                        codigo[i] = check[i];
                    }
                    Upt_Coor(codigo);
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