#include "../include/SPI.hpp"

//Public Methods
SPI::SPI(uint8_t MOSI, uint8_t MISO, uint8_t SCK, uint8_t SS){
    this->MOSI = MOSI;
    this->MISO = MISO;
    this->SCK = SCK;
    this->SS = SS;
}