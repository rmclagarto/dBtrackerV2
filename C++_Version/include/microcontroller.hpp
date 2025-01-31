#pragma once


#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>
#include <nlohmann/json.hpp>



#include "I2C.hpp"
#include "SPI.hpp"
#include "GPIO.hpp"
#include "Timer.hpp"

using json = nlohmann::json;
using namespace std;

class Microcontroller
{
private:
    GPIO gpio;
    I2C i2c;
    SPI spi;


    bool isByte(int byte);

public:
    Microcontroller(const std::string& microName);

    void setupPin(uint8_t pin, bool mode);
    void writeDigitalPin(uint8_t pin, bool value);
    double readPin(uint8_t pin);
    void writeAnalogPin(uint8_t pin, double value);
    

    //I2C Methods
    void I2Cbegin(uint8_t address = 0);
    bool I2Cavailable();
    void I2Cwrite(uint8_t data);

};