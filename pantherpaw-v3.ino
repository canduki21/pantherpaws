#include <SoftwareSerial.h>

char data = 0;

#define ENA 5  // Enable A (Speed Control Motor 1)
#define IN1 6  // Motor 1 Direction 1
#define IN2 7  // Motor 1 Direction 2

#define ENB 4  // Enable B (Speed Control Motor 2)
#define IN3 8  // Motor 2 Direction 1
#define IN4 9  // Motor 2 Direction 2

void setup() {
    Serial.begin(9600); // Start serial communication with HC-05

    pinMode(ENA, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    
    pinMode(ENB, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, 0); // Stop Motor 1 at startup

    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, 0); // Stop Motor 2 at startup
}

void loop() {
    if (Serial.available()) { // Check if data is available
        data = Serial.read(); // Read the incoming data

        if (data == '1') { // Move forward
            digitalWrite(IN1, HIGH);
            digitalWrite(IN2, LOW);
            analogWrite(ENA, 255); // Adjust speed
            
            digitalWrite(IN3, HIGH);
            digitalWrite(IN4, LOW);
            analogWrite(ENB, 240); // Adjust speed
        }
        else if (data == '2') { // Move backward
            digitalWrite(IN1, LOW);
            digitalWrite(IN2, HIGH);
            analogWrite(ENA, 255);
            
            digitalWrite(IN3, LOW);
            digitalWrite(IN4, HIGH);
            analogWrite(ENB, 240);
        }
        else if (data == '0') { // Stop motors
            digitalWrite(IN1, LOW);
            digitalWrite(IN2, LOW);
            analogWrite(ENA, 0);
            
            digitalWrite(IN3, LOW);
            digitalWrite(IN4, LOW);
            analogWrite(ENB, 0);
        }
    }
}

