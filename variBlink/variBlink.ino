/*
  VariBlink

  Flashes an LED. The period and duty cycle are configurable.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified  8 May 2014
  by Scott Fitzgerald
  modified  2 Sep 2016
  by Arturo Guadalupi
  modified  8 Sep 2016
  by Colby Newman
  Modified 19 Mar 2018
  by Bl4krat
*/


uint16_t period    = 1000; // in milliseconds. 2000 = 2 seconds
uint16_t dutyCycle = 3;    // what percent of time id LED on?
uint16_t onTime    = int(period * (dutyCycle / 100.0));
uint16_t offTime   = period - onTime;


void setup() {
  
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  
  //debug feedback
  Serial.begin(115200);
  Serial.print("onTime : ");
  Serial.println(onTime);
  Serial.print("offTime: ");
  Serial.println(offTime);
}


void loop() {

  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(onTime);                     // wait for the on-time
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(offTime);                    // wait for a second
}
