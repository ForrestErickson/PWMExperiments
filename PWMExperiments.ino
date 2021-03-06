/* PWMExperiments.ino
 *  Forrest Erickson
 *  Date: 20210411
 * Stared with code from: https://randomnerdtutorials.com/esp32-pwm-arduino-ide/
 * Experiment with setting of PWM to find frequency and resolution limitations.
 * 
 */


// the number of the LED pin
const int builtinLEDpin = 2;   //  2 corresponds to GPIO16 built in LED.
const int ledPin12 = 12;  // 12 corresponds to GPIO12
//const int ledPin = 13;  // 13 corresponds to GPIO13
const int ledPin14 = 14;  // 14 corresponds to GPIO14

// setting PWM properties
const int freqLED12 = 5000;
const int freqLED14 = 50000;

const int ledChannel_12 = 0;
const int ledChannel_14 = 1;
//                                Set Freq: 80KHz    100KHz   200KHz  50KHz 
//const int resolution = 8;   // Freq became 80.00    100.00  200.00
//const int resolution = 9;   // Freq became 80.00    100.0   156.3
const int resolution = 10;  // Freq became 78.13    78.13   78.13   50.00  
//const int resolution = 11;  // Freq became 39.06    39.06    39.06    
//const int resolution = 12;  // Freq became 19.53    19.53   19.53 
const int NUMSTEPS = pow(2,resolution)-1; 

const int DELAYTIME = 2;
void setup(){
  // configure LED PWM functionalitites
  ledcSetup(ledChannel_12, freqLED12, resolution);
  ledcSetup(ledChannel_14, freqLED14, resolution);    //Last setting takes precidence
  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(ledPin12, ledChannel_12);
  ledcAttachPin(ledPin14, ledChannel_14);
}
 
void loop(){
  // increase the LED brightness
  for(int dutyCycle = 0; dutyCycle <= NUMSTEPS; dutyCycle++){   
    // changing the LED brightness with PWM
    ledcWrite(ledChannel_12, dutyCycle);
    ledcWrite(ledChannel_14, dutyCycle);
    delay(DELAYTIME);
  }
    // decrease the LED brightness
  for(int dutyCycle = NUMSTEPS; dutyCycle >= 0; dutyCycle--){
    // changing the LED brightness with PWM
    ledcWrite(ledChannel_12, dutyCycle);   
    ledcWrite(ledChannel_14, dutyCycle);
    delay(DELAYTIME);
  }
}

  
