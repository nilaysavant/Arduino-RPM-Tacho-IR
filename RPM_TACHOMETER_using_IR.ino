/*
  RPM TACHOMETER using IR proximity sensor

  AUTHOR: Nilay Savant

  
 */

int sensor_pin = 22; // IR sensor connection
volatile unsigned long timer = 0, now_time = 0, pre_time = 0;
volatile float rpm = 0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(sensor_pin, INPUT);
  
  attachInterrupt(digitalPinToInterrupt(sensor_pin), isr, RISING); // detects interrupt on rising  edge
  pre_time = micros();
}

// the loop routine runs over and over again forever:
void loop() 
{
  rpm = (1/(timer*pow(10,-6)))*60;
  Serial.println(rpm);
}

// custom functions
void isr() // count ISR
{
  now_time = micros();
  timer = now_time - pre_time;
  pre_time = now_time;
}


