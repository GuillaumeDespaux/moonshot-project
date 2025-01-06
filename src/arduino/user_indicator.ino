void request_success(void){
    digitalWrite(green_led, HIGH);
    delay(500);
    digitalWrite(green_led, LOW);
}

void request_failed(void){
    digitalWrite(red_led, HIGH);
    delay(500);
    digitalWrite(red_led, LOW);
}

void request_processing_start(void){
    digitalWrite(yellow_led, HIGH);
} 

void request_processing_end(void){
    delay(500);
    digitalWrite(yellow_led, LOW);
}
void request_internet_connection(void){
    digitalWrite(blue_led, HIGH);
    delay(500);
    digitalWrite(blue_led, LOW);
}