#define TRIG_PIN1 2 // Ultrasonic sensor 1 trigger pin
#define ECHO_PIN1 3 // Ultrasonic sensor 1 echo pin
#define TRIG_PIN2 4 // Ultrasonic sensor 2 trigger pin
#define ECHO_PIN2 5 // Ultrasonic sensor 2 echo pin
#define TRIG_PIN3 6 // Ultrasonic sensor 3 trigger pin
#define ECHO_PIN3 7 // Ultrasonic sensor 3 echo pin

const int motorA1 =8;  // IN1
const int motorA2 =10;  // IN2
const int enableA =9;  // ENA (PWM)

const int motorB1 =12;  // IN3
const int motorB2 =13;  // IN4
const int enableB =11; // ENB (PWM)


#define MAX_DISTANCE 200 // Maximum distanc

void setup() {
  
  Serial.begin(9600);
  pinMode(TRIG_PIN1, OUTPUT);
  pinMode(ECHO_PIN1, INPUT);
  pinMode(TRIG_PIN2, OUTPUT);
  pinMode(ECHO_PIN2, INPUT);
  pinMode(TRIG_PIN3, OUTPUT);
  pinMode(ECHO_PIN3, INPUT);
  // Initialize motor control
  
  
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(enableA, OUTPUT);
 
   // Adjust the motor speed as needed
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(enableB, OUTPUT);
  
}
  
void loop() {
  int distance1 = getDistance1();
  int distance2 = getDistance2();
  int distance3 = getDistance3();

  if (distance1 < 10){
    stopMotors();
    delay(1000);// turn 0.5 secomd
    reverse();
    delay(1000);// reverse 1 second
   }else  {
    driveForward();
   }
  if (distance2 < 10) {
    stopMotors();//turn 0.5 second
    delay(10);
    turnRight();
    delay(1000);//turnRight 1 second
  }
  if (distance3 < 10) {
    stopMotors();//turn 0.5 second
    delay(10);
    turnLeft();
    delay(1000);//turnLeft 1 second
  }
  
}

int getDistance1(){
  digitalWrite(TRIG_PIN1, LOW);
  delayMicroseconds(1);
  digitalWrite(TRIG_PIN1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN1, LOW);
  return pulseIn(ECHO_PIN1, HIGH) / 58;
}

int getDistance2(){
  digitalWrite(TRIG_PIN2, LOW);
  delayMicroseconds(1);
  digitalWrite(TRIG_PIN2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN2, LOW);
  return pulseIn(ECHO_PIN2, HIGH) / 58;
}

int getDistance3(){
  digitalWrite(TRIG_PIN3, LOW);
  delayMicroseconds(1);
  digitalWrite(TRIG_PIN3, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN3, LOW);
  return pulseIn(ECHO_PIN3, HIGH) / 58;
}




void stopMotors(){
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  analogWrite(enableA, 0);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, LOW);
  analogWrite(enableB, 0);
}

void reverse(){
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  analogWrite(enableA, 100); 

  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
  analogWrite(enableB, 100);
}

void driveForward(){
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  analogWrite(enableA, 100);
  
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
  analogWrite(enableB, 100);
  
}
void turnRight(){
  digitalWrite(motorA1, HIGH);
  digitalWrite(motorA2, LOW);
  analogWrite(enableA, 100);
  
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, HIGH);
  analogWrite(enableB, 100);
  
}
void turnLeft(){
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, HIGH);
  analogWrite(enableA, 100);
  
  digitalWrite(motorB1, HIGH);
  digitalWrite(motorB2, LOW);
  analogWrite(enableB, 100);
}
