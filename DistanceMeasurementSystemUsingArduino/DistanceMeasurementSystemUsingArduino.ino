#include <LiquidCrystal.h>

LiquidCrystal lcd(10,9,8,7,6,5); // Create an LCD object. Parameters: (RS, E, D4, D5, D6, D7):

const int trigPin = 12;
const int echoPin = 11;

long duration;
int distanceCm, distanceInch;

void setup() {
  // put your setup code here, to run once:

  analogWrite(6,100);
  lcd.begin(16, 2); // Specify the LCD's number of columns and rows. Change to (20, 4) for a 20x4 LCD
  lcd.setCursor(4,0);
  lcd.print("Distance");
  lcd.setCursor(3,1);
  lcd.print("Measurement");
  delay(400);
  pinMode(trigPin, OUTPUT);  // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);  // Sets the echoPin as an Input 
  Serial.begin(9600);  // Starts the serial communication
}

void loop() {
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  //delayMicroseconds(10);
  //digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration*0.034/2;
  distanceInch = duration*0.0133/2;
  
  // For Serial Monitor
  Serial.print("Distance:CM ");  
  Serial.println(distanceCm);  
  Serial.print("Distance:Inch ");  
  Serial.println(distanceInch);  
  
  lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
  lcd.print("Distance: "); // Prints string "Distance" on the LCD
  lcd.print(distanceCm); // Prints the distance value from the sensor
  lcd.print("  cm");
  delay(200);
  
  lcd.setCursor(0,1);
  lcd.print("Distance: ");
  lcd.print(distanceInch);
  lcd.print(" inch");
  delay(200);
}
