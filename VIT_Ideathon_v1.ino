const int trigPin = A0;
const int echoPin = A1;
const int LED     = 3;
const int IR      = A2;

int i,switch_mode;

float duration, distance,duration_on, distance_on;

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position


void setup() 
{
  myservo.attach(9);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LED,OUTPUT);
  //IR Config 
  Serial.begin(9600);
}

void loop() 
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);

  if(distance<7)
  {
    switch_mode=1;
    while(switch_mode==1)
    {
      for (pos = 0; pos <= 180; pos += 1) 
      { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
      if(distance_on<5)
      break;
    }
   }
}
