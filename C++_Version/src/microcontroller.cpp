
/*
    3. Controle de Tempo
        delay(ms) → Pausa a execução por ms milissegundos.
        delayMicroseconds(us) → Pausa a execução por us microssegundos.
        millis() → Retorna o tempo em milissegundos desde que o Arduino foi ligado.

    4. Comunicação Serial
        Serial.begin(baudRate) → Inicia a comunicação serial.
        Serial.print(data) → Envia dados via serial.
        Serial.available() → Retorna se há dados recebidos disponíveis.
        Serial.read() → Lê um byte da comunicação serial.

    5. Interrupções
        attachInterrupt(interrupt, isr, mode) → Ativa uma interrupção externa.
        detachInterrupt(interrupt) → Desativa uma interrupção externa.

    6. Comunicação I2C e SPI (Opcional, para periféricos)
        // Funções relacionadas ao I2C
        Wire.begin() → Inicia comunicação I2C como mestre.
        Wire.begin(address) → Inicia comunicação I2C como escravo, com o endereço especificado.
        Wire.requestFrom(address, quantity) → Solicita um número de bytes de um dispositivo I2C com o endereço 'address'.
        Wire.beginTransmission(address) → Inicia uma transmissão para o dispositivo com o endereço especificado.
        Wire.write(data) → Envia um byte de dados para o dispositivo I2C.
        Wire.endTransmission() → Finaliza a transmissão de dados e libera o barramento I2C.
        Wire.available() → Retorna o número de bytes disponíveis para leitura.
        Wire.read() → Lê um byte de dados do dispositivo I2C.
        Wire.setClock(clockSpeed) → Ajusta a velocidade do barramento I2C, onde 'clockSpeed' pode ser, por exemplo, 100000 ou 400000.

        // Funções relacionadas ao SPI
        SPI.begin() → Inicia a comunicação SPI.
        SPI.beginTransaction(SPISettings(speed, bitOrder, dataMode)) → Configura a transação SPI com a velocidade, ordem de bits e modo de dados.
        SPI.transfer(data) → Envia e recebe um byte de dados via SPI.
        SPI.endTransaction() → Finaliza a transação SPI.
        SPI.end() → Encerra a comunicação SPI.
*/
#include <stdexcept>
#include "../include/microcontroller.hpp"


Microcontroller::Microcontroller(const std::string& microName)
{
    auto found = false;
    
    std::ifstream inputFile("boardsConfiguration.json");
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
