/*
 * File: main.cpp
 * Project: mg995-closed-loop-axis-control-system
 * Description: Sweeps an MG995 servo back and forth and logs the current angle to Serial.
 *              Demonstrates simple servo control using the Arduino Servo library.
 *
 * Hardware: MG995 servo (signal on pin 10 by default), Arduino-compatible board.
 *           Use an external 5V power supply for the servo if it draws significant current.
 *
 * Behavior:
 *  - Serial output at 9600 baud reports the current angle (degrees).
 *  - Servo sweeps from 0 to 180 and back in configurable steps and delays.
 *
 * Notes:
 *  - Requires the Arduino "Servo" library. Add it to PlatformIO `lib_deps` or place the
 *    library in the `lib/` folder. Example platformio.ini entry:
 *      lib_deps = arduino-libraries/Servo@^1.1.8
 *  - Keep servo ground and board ground common when using an external supply.
 *
 * Author: AkshitaAg25
 * Created: 2026-02-19
 */

#include <Arduino.h>
#include <Servo.h>

// Configuration constants
const int SERVO_PIN = 10;                 // PWM pin connected to servo signal
const unsigned long SERIAL_BAUD = 9600;  // Serial baud rate
const int SWEEP_STEP = 10;               // Degrees per step when sweeping
const unsigned long STEP_DELAY_MS = 500; // Delay between steps in milliseconds

Servo myServo;

void setup() {
    // Initialize serial and servo
    Serial.begin(SERIAL_BAUD);
    myServo.attach(SERVO_PIN);
    Serial.println("Servo initiate");
}

void loop() {
    // Sweep up 0 -> 180
    for (int angle = 0; angle <= 180; angle += SWEEP_STEP) {
        myServo.write(angle);
        Serial.print("Angle: ");
        Serial.println(angle);
        delay(STEP_DELAY_MS);
    }

    // Sweep down 180 -> 0
    for (int angle = 180; angle >= 0; angle -= SWEEP_STEP) {
        myServo.write(angle);
        Serial.print("Angle: ");
        Serial.println(angle);
        delay(STEP_DELAY_MS);
    }
}