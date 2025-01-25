
/*    
    4. Comunicação Serial
        Serial.begin(baudRate) → Inicia a comunicação serial.
        Serial.print(data) → Envia dados via serial.
        Serial.available() → Retorna se há dados recebidos disponíveis.
        Serial.read() → Lê um byte da comunicação serial.

    5. Interrupções
        attachInterrupt(interrupt, isr, mode) → Ativa uma interrupção externa.
        detachInterrupt(interrupt) → Desativa uma interrupção externa.
*/


#include "../include/microcontroller.hpp"


Microcontroller::Microcontroller(const std::string& microName)
{
    auto found = false;
    
    std::ifstream inputFile("./boardsInfo/boardsConfiguration.json");
    if(!inputFile.is_open()){
        throw std::runtime_error("File not found");
    }


    json j;
    inputFile >> j;

    for (auto& item : j.items()) {
        if (item.key() == microName) {
            found = true;
            //Extracting GPIO information
            std::vector<int> digitalPins = item.value().at("Digital_Pins");
            std::vector<int> analogPins = item.value().at("Analog_Pins");
            std::vector<int> pwmPins = item.value().at("PWM_Pins");
            
            this->gpio = GPIO(digitalPins, analogPins, pwmPins);


            //I2C information
            uint8_t SCL = item.value().at("I2C_Pins").at("SCL");
            uint8_t SDA = item.value().at("I2C_Pins").at("SDA");

            this->i2c = I2C(SCL, SDA);


            //Extract SPI information
            uint8_t mosi = item.value().at("SPI_Pins").at("MOSI");
            uint8_t miso = item.value().at("SPI_Pins").at("MISO");
            uint8_t sck = item.value().at("SPI_Pins").at("SCK");
            uint8_t ss = item.value().at("SPI_Pins").at("SS");

            this->spi = SPI(mosi, miso, sck, ss);


            break;
        }
    }
            

    if(!found){
        throw std::runtime_error("Microcontroller not found");
    }

}


bool Microcontroller::isByte(int byte){
    return byte >= 0 && byte <= 255;
}


    /*
    // Manipulação de GPIO (Pinos Digitais)
    void Microcontroller::setupPin(uint8_t pin, bool mode)
    {
        gpio.setup(pin, mode);
    }

    void Microcontroller::writeDigitalPin(uint8_t pin, bool value)
    {
        gpio.writeDigitalPin(pin, value);
    }

    double Microcontroller::readPin(uint8_t pin)
    {
        //return gpio.readPin(pin);
        return 0.0;
    }

    void Microcontroller::writeAnalogPin(uint8_t pin, double value)
    {
        gpio.writeAnalogPin(pin, value);
    }
    */


void Microcontroller::I2Cbegin(uint8_t address){
    i2c.begin(address);
}


bool Microcontroller::available(){
    return i2c.available();
}
