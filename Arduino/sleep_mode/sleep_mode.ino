/* Libraries */
#include <avr/sleep.h> //Contains the methods used to control the sleep modes


void configure_sleep_mode(unsigned int sleepmode, unsigned int interruptPin);
void wakeUp();


void setup() {
  // put your setup code here, to run once:

    Serial.begin(115200); //sets the baud rate
    while (!Serial) {
        ; // wait for serial port to connect. Needed for native USB port only
    }
    configure_sleep_mode(5, 2);
}

void loop() {
  // put your main code here, to run repeatedly:
  
}

/*
 * Description: Configures the Arduino Uno for one of 6 sleep modes. The board is woken with interrupt pin 2 or 3. Used
 * for testing current draw during sleep modes and interrupt pin capability.
 * Accepts: unsigned int sleepmode - the sleep mode for the Arduino to enter (see switch-case)
 *          unsigned int interruptPin - the pin # to configure as an interrupt (Digital 2 or 3 for Arduino)
 * Returns: void
 */
void configure_sleep_mode(unsigned int sleepmode, unsigned int interruptPin) {
    sleep_enable(); //Enables sleep mode
    pinMode(interruptPin, INPUT_PULLUP); //Assign pin 2 or 3 as input pullup
    attachInterrupt(digitalPinToInterrupt(interruptPin), wakeUp, LOW); //set pin 2 or 3 as an interrupt that jumps to wakeUp() when triggered LOW
    switch (sleepmode) { //selects which sleep mode to enter
        case 1:
            set_sleep_mode(SLEEP_MODE_IDLE);
            break;
        case 2:
            set_sleep_mode(SLEEP_MODE_ADC);
            break;
        case 3:
            set_sleep_mode(SLEEP_MODE_PWR_DOWN);
            break;
        case 4:
            set_sleep_mode(SLEEP_MODE_PWR_SAVE);
            break;
        case 5:
            set_sleep_mode(SLEEP_MODE_STANDBY);
            break;
        case 6:
            set_sleep_mode(SLEEP_MODE_EXT_STANDBY);
            break;
        default:
            set_sleep_mode(SLEEP_MODE_IDLE);
            break;
    }
    bitClear(TIMSK0, 0);  //stops the millis() timer so that sleep modes aren't waken by it (SLEEP_MODE_IDLE is woken by the millis() timer)
    //sleep_enable(); //Enables sleep mode
    sleep_cpu(); //activates the set sleep mode
    
    //Serial.println("Just woke up!");
    bitSet(TIMSK0, 0); //starts the millis() timer back up
    return;
}


/*
 * Description: ISR used to disable sleep mode and detach the interrupt pin
 * Accepts: void
 * Returns: void
 */
void wakeUp(){
    sleep_disable(); //Disable sleep mode
    detachInterrupt(digitalPinToInterrupt(2)); //remove pin as interrupt
    detachInterrupt(digitalPinToInterrupt(3)); //remove pin as interrupt
    return;
}
