
// defines pins numbers
const int trigPin = A5;
const int echoPin = A4;
int mp1 = 7;
int mp2 = 8;
int powerLeft = 6;
int mp3 = 13;
int mp4 = 12;
int powerRight = 11;
int lineSensorFront = 2;
//int lineSensorBack = 4;
// defines variables
long duration;
int distance;
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(mp1,OUTPUT);
  pinMode(mp2,OUTPUT);
  pinMode(powerLeft,OUTPUT);
  pinMode(mp3,OUTPUT);
  pinMode (mp4, OUTPUT);
  pinMode (powerRight, OUTPUT);
  //pinMode(LED_BUILTIN, OUTPUT);
  pinMode(lineSensorFront, INPUT); //setting the front line sensor
  Serial.begin(9600); // Starts the serial communication
  delay(3000);
}
void loop() {
  // Clears the trigPin
  analogWrite(trigPin, 0);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  analogWrite(trigPin, 255);
  delayMicroseconds(10);
  analogWrite(trigPin, 0);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, 255);
  // Calculating the distance
  distance = duration*0.034/2;
  //Serial.print(distance);
  //Serial.print('\n');
  // Prints the distance on the Serial Monitor
  if (digitalRead(lineSensorFront)== HIGH) {//if front sensor is touching the line 
    analogWrite(powerLeft, 255);
    analogWrite(powerRight, 255);
    digitalWrite(mp1, LOW);
    digitalWrite(mp2, HIGH);
    digitalWrite(mp3, LOW);
    digitalWrite(mp4, HIGH);
    //delayMicroseconds(10);
  }
  else if (distance < 76 && distance>=0) { //if the ultrasonic sensor sees something in it
    analogWrite(powerLeft, 255);
    analogWrite(powerRight, 255);
    digitalWrite(mp1, HIGH);
    digitalWrite(mp2, HIGH);
    digitalWrite(mp3, HIGH);
    digitalWrite(mp4, LOW);
    //delayMicroseconds(10);
  } 
  else{
    analogWrite(powerLeft, 255);
    analogWrite(powerRight, 255);
    digitalWrite(mp1, LOW);
    digitalWrite(mp2, HIGH);
    digitalWrite(mp3, HIGH);
    digitalWrite(mp4, LOW);
  }
}

