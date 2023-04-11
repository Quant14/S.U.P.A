#include <ezButton.h>

// Sensor
//SoftwareSerial mySerial(3, 2);

int lastButton;

//unsigned int HighByte = 0;
//unsigned int LowByte  = 0;
//unsigned int Len  = 0;

// MOTOR 1 PINS
int enA_first = 3;
int in1 = 4;
int in2 = 5;

// MOTOR 2 PINS
int enB_first = 6;
int in3 = 7;
int in4 = 8;

// MOTOR 3 PINS
int enA_second = 9;
int in5 = 10;
int in6 = 11;

void setup()
{
  // Оправи първия мотор
  pinMode(enA_first, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  // Оправи втория мотор
  pinMode(enB_first, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Оправи третия мотор
  pinMode(enA_second, OUTPUT);
  pinMode(in5, OUTPUT);
  pinMode(in6, OUTPUT);

  // Оправи моторите
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(in5, LOW);
  digitalWrite(in6, LOW);

  pinMode(2, INPUT_PULLUP);  // enable the internal pull-up resistor
  lastButton = digitalRead(2);  

  // Започни комуникацията за сензора
  Serial.begin(9600);
  //mySerial.begin(9600);
  
}

void loop()
{
  int button = digitalRead(2);
  if (lastButton != button) { // If the button is pressed
    Serial.println("Button pressed!"); // Print a message to the serial monitor
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    analogWrite(enA_first, 255);

    delay(7000);

    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);

    delay(1000);

    digitalWrite(in5,HIGH);
    digitalWrite(in6,LOW);
    analogWrite(enA_second, 255);

    delay(10000);

    digitalWrite(in5, LOW);
    digitalWrite(in6, LOW);

    delay(1000);

    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    analogWrite(enA_first, 255);

    delay(3000);

    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);

    delay(1000);

    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
    analogWrite(enB_first, 255);

    delay(40000);

    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    analogWrite(enB_first, 255);

    delay(40000);

    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);

    delay(1000);

    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    analogWrite(enA_first, 255);

    delay(10000);

    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);

    lastButton = button;
  }

  delay(100); // Delay for a short period of time
}