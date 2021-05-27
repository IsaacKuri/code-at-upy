void uv_lamp_on(){
    digitalWrite(uv_lamp, LOW);
}
void uv_lamp_off(){
    digitalWrite(uv_lamp, HIGH);
}

bool utils_check_door(){
    if (!digitalRead(door))
    {
        sleept = 0;
        oled_sleep = false;
        uv_lamp_off();
        old_state = state;
        state = cdoor;
        return true;
    }
    else{
        return false;
    }
}