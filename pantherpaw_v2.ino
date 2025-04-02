   #include <SoftwareSerial.h>

char data = 0;

#define ENA 5  // Enable A (Speed Control)
#define IN1 6  // Motor Direction 1
#define IN2 7  // Motor Direction 2

void setup() {
    Serial.begin(9600); // Start serial communication with HC-05

    pinMode(ENA, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, 0); // Stop motor at startup
}

void loop() {
    if (Serial.available()) { // Check if data is available
        data = Serial.read(); // Read the incoming data

        if (data == '1') { // Move forward
            digitalWrite(IN1, HIGH);
            digitalWrite(IN2, LOW);
            analogWrite(ENA, 150); // Adjust speed (0-255)
        }
        else if (data == '2') { // Move backward
            digitalWrite(IN1, LOW);
            digitalWrite(IN2, HIGH);
            analogWrite(ENA, 150); // Adjust speed
        }
        else if (data == '0') { // Stop motor
            digitalWrite(IN1, LOW);
            digitalWrite(IN2, LOW);
            analogWrite(ENA, 0);
        }
    }
}


