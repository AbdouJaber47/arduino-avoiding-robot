
#define in1 5
#define in2 6
#define fna 3

#define in3 7
#define in4 8
#define fnb 10

#define echo 12
#define trig 11

#include <Servo.h>
Servo servo;

float distance, duree;
float leftDistance, rightDistance; 



void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(fna, OUTPUT);
  pinMode(fnb, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  servo.attach(4);
  servo.write(70);
  Serial.begin(115200);
}

void loop() {
  ultrasonic(); 

  
  leftDistance = distanceLeft();
  rightDistance = distanceRight();

  if (distance <= 25) {
    digitalWrite(fna, LOW); 
    digitalWrite(fnb, LOW);
    delay(500);

    digitalWrite(in3, LOW); 
    digitalWrite(in4, HIGH);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);

    digitalWrite(fna, 150);
    digitalWrite(fnb, 150);
    delay(250);
    digitalWrite(fna, LOW);
    digitalWrite(fnb, LOW);

   
    if (leftDistance > rightDistance) {
      digitalWrite(in3, LOW); 
      digitalWrite(in4, LOW);
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(fna, 190);
      delay(250);
      digitalWrite(fna, LOW);
    } else { 
      digitalWrite(in3, HIGH); 
      digitalWrite(in4, LOW);
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(fnb, 190);
      delay(250);
      digitalWrite(fnb, LOW);
    }
  } else {
    digitalWrite(in3, HIGH); 
    digitalWrite(in4, LOW);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(fna, 100);
    digitalWrite(fnb, 100);
  }
}

void ultrasonic() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duree = pulseIn(echo, HIGH);
  distance = 0.034 * duree / 2;

  Serial.print("distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(20);
}

float distanceLeft() {
  servo.write(0);
  delay(500);
  ultrasonic();
  servo.write(70);
  return distance; 
}

float distanceRight() {
  servo.write(180);
  delay(500);
  ultrasonic();
  servo.write(70);
  return distance; 
}
