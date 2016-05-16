#include <Servo.h>
Servo servo;

const int potPin = A0;
const int buttonPin = 11;
#define GREEN 5
#define BLUE 6
#define RED 3

int servoPosition = 0;
int teaState = 0;
int potValue = 0;
int brewTime = 0;
int buttonState = 0;

void setup(){
  servo.attach(9);
  servo.write(90);
  
  Serial.begin(9600);
  
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(buttonPin, INPUT);
  
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
  digitalWrite(RED, HIGH);
  
}

void loop(){
  potValue = analogRead(potPin);
  unsigned long brewTime = 60000 * map(potValue,1023,0,1,6);
  
  Serial.print("brewTime");
  Serial.println(brewTime);
  
  buttonState = digitalRead(buttonPin);
  
  if(buttonState == HIGH){
    servo.write(90);
    analogWrite(RED, 240);
    analogWrite(GREEN, 255);
    Serial.println("Brewing part 1 commenced!");
    
    delay(brewTime/2);

    Serial.println("Commence half-time wiggle!");
    servo.write(130);
    delay(500);
    servo.write(90);
    delay(500);
    servo.write(130);
    delay(500);
    servo.write(90);
    Serial.println("Half-time wiggle ceased, brewing part 2 will continue");
    
    delay(brewTime/2);
    
    servo.write(150);
    analogWrite(RED, 255);
    digitalWrite(GREEN, 240);
  }
  else{
    servo.write(150);
    analogWrite(GREEN, 250);
  }
}
