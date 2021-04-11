/* PWMExperiments.ino
 * From: https://randomnerdtutorials.com/esp32-pwm-arduino-ide/
 * 
 */


// the number of the LED pin
const int builtinLEDpin = 2;   //  2 corresponds to GPIO16 built in LED.
const int ledPin12 = 12;  // 12 corresponds to GPIO12
//const int ledPin = 13;  // 13 corresponds to GPIO13
const int ledPin14 = 14;  // 14 corresponds to GPIO14

// setting PWM properties
const int freqLED12 = 5000;
const int freqLED14 = 80000;

const int ledChannel_12 = 0;
const int ledChannel_14 = 1;
const int resolution = 8;


void setup(){
  // configure LED PWM functionalitites
  ledcSetup(ledChannel_12, freqLED12, resolution);
  ledcSetup(ledChannel_14, freqLED14, resolution);
  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(ledPin12, ledChannel_12);
  ledcAttachPin(ledPin14, ledChannel_14);
}
 
void loop(){
  // increase the LED brightness
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    // changing the LED brightness with PWM
    ledcWrite(ledChannel_12, dutyCycle);
    ledcWrite(ledChannel_14, dutyCycle);
    delay(15);
  }
    // decrease the LED brightness
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    // changing the LED brightness with PWM
    ledcWrite(ledChannel_12, dutyCycle);   
    ledcWrite(ledChannel_14, dutyCycle);
    delay(15);
  }
}

  
