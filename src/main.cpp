#include "iostream"
#include <wiringPi.h>

#define BeepPin 0

static void BuzzerBeepPulse(int pin) {
    digitalWrite(pin, LOW);
    delay(2);
    digitalWrite(pin, HIGH);
    delay(2);
}

static void BuzzerBeep(int pin) {
    for(auto time = 0; time < 250; time++) {
        BuzzerBeepPulse(pin);
    }
}

static void BuzzerBeep(int pin, int times) {
    for (auto time = 0; time < times; time++) {
        delay(200);
        BuzzerBeep(pin);
    }
}

static void BuzzerBeepSuccess(int pin) {
    BuzzerBeep(pin, 2);
    delay(2000);
}

static void BuzzerBeepFailed(int pin) {
    BuzzerBeep(pin, 4);
    delay(2000);
}

static void BuzzerBeepFailedCritical(int pin) {
    BuzzerBeep(pin, 10);
    delay(1000);
}

int main() {
    if (-1 == wiringPiSetup()) {
        std::cout << "setup wiringPi failed!" << std::endl;
        return 1;
    }

    //Set GPIO pin
    pinMode(BeepPin, OUTPUT);

    BuzzerBeepSuccess(BeepPin);
    BuzzerBeepFailed(BeepPin);

    return 0;
}