#pragma once

/*
    1. Manipulação de GPIO (Pinos Digitais)
        pinMode(pin, mode) → Define se um pino é entrada (INPUT) ou saída (OUTPUT).
        digitalWrite(pin, value) → Define o valor de um pino digital (HIGH ou LOW).
        digitalRead(pin) → Lê o estado de um pino digital (HIGH ou LOW).

    2. Operações com Pinos Analógicos
        analogRead(pin) → Lê um valor analógico (0 a 1023).
        analogWrite(pin, value) → Escreve um valor PWM (0 a 255).
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <vector>

//#include <avr/io.h>

class GPIO
{
private:
    bool stateOperative;
    
    std::vector<int> digitalPins;
    std::vector<int> analogPins;
    std::vector<int> pwmPins;

    bool configuredPins[20] = {false};


    void setPortBit(volatile uint8_t &port, uint8_t pin, bool value);
    bool isDigitalPin(uint8_t pin);
    bool isAnalogPin(uint8_t pin);
    bool isConfiguredPin(uint8_t pin);
    void markAsConfiguredPin(uint8_t pin);
    void configurePort(uint8_t portRegister, uint8_t pin, bool mode);
    void configurePin(uint8_t pin, bool mode);

public:
    GPIO() = default;
    GPIO(std::vector<int> digitalPins, std::vector<int> analogPins, std::vector<int> pwmPins);

    void setup(uint8_t pin, bool stateOperative);
    void writeDigitalPin(uint8_t pin, bool stateOperative);
    bool readDigitalPin(uint8_t pin);
    void writeAnalogPin(uint8_t pin, bool stateOperative);
    int readAnalogPin(uint8_t pin);   
};