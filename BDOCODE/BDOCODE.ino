/*
 * Box Disinfektan Automatic
 * 2020
 * Present by Ijuj & Acep
*/
 
// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int relay = 2;

//define LED
const int LEDON = 12; // merah
const int LEDOFF = 11; // hejo

// defines variables
long duration;
int distance; 
void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(relay, OUTPUT);
pinMode(LEDON, OUTPUT);
pinMode(LEDOFF, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}
void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance = duration*0.034/2;

// Prints the distance on the Serial Monitor

  if (distance <= 100){
    delay(2000);
    Serial.print("Distance: ");
    Serial.println(distance);
    digitalWrite(relay, HIGH); // Pump On
    digitalWrite(LEDON, HIGH);
    digitalWrite(LEDOFF, LOW);
    delay(5000); // nDuration of pump on
    // pump off
    //digitalWrite(LEDON, LOW); //change led 
    //digitalWrite(LEDOFF, HIGH); 
    digitalWrite(relay, LOW); // pump off
    delay(10000); // delay agar ga keinput lagi orang biar keluar 
  }else {
    digitalWrite(relay, LOW);
    digitalWrite(LEDON, LOW);
    digitalWrite(LEDOFF, HIGH);
    }
}
