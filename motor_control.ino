//codestill indevelopment
//currently the motor can move and when it encounters obstacle it bturns left
//and checks then turns right 
//then reverses or 
//check for futher deveopmnets in a few days or weeks 
//@ tmundere
const int motorPin1  = 5;  // Pin 14 of L293
const int motorPin2  = 4;  // Pin 10 of L293
//Motor B
const int motorPin3  = 3; // Pin  7 of L293
const int motorPin4  = 2;  // Pin  2 of L293

int trigPin = 11;    //Trig - green Jumper
int echoPin = 12;    //Echo - yellow Jumper
long duration, cm, inches;

//This will run only one time.
void setup(){
   //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

     //Set pins as outputs
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);   
    Serial.begin(9600);
  
}


void loop(){
  

      //analogWrite(motorPin1, 180); //  right motor  going forward
      //analogWrite(motorPin3, 180); // left motor going forward
     //analogWrite(motorPin2, 180);// right motor backwards
      // analogWrite(motorPin4, 180); // left motor backwards 
     
    //Motor Control - Motor A: motorPin1,motorpin2 
    //              & Motor B: motorpin3,motorpin4

     
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // convert the time into a distance
  cm = (duration/2) / 29.1;
  inches = (duration/2) / 74; 
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  if (cm <10)
  {
  //This code will make the robot to turn left
  Serial.println("obstacle ahead turning left");
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 180);
    analogWrite(motorPin3, 180);
    analogWrite(motorPin4, 0);
    delay(1000); 
    if (cm<10)
    {
     //This code will  make the robot to turn  right 
     Serial.println("obstacle left turning right");
    analogWrite(motorPin1, 180);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 180);
    delay(1000);
    if (cm<10)
    {
       //This code will make robot backward
     Serial.println(" no way out reverse ");
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 180);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 180);
    delay(5000);

    if (cm<10)
    {
     //And this code will stop motors
    Serial.println(" stop");
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 0); 
    delay (5000);
    }
    }

        }

     }

else {
    //This code  will  make the robot move forward
    Serial.println(" Robot moving forward ");
    analogWrite(motorPin1, 180);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 180);
    analogWrite(motorPin4, 0);
    delay(5000); 
   
} 
  
      
    


    
}

