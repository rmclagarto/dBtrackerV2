#pragma once


/*

    Wire.begin() → Inicia comunicação I2C como mestre.
    Wire.begin(address) → Inicia comunicação I2C como escravo, com o endereço especificado.
    Wire.requestFrom(address, quantity) → Solicita um número de bytes de um dispositivo I2C com o endereço 'address'.
    Wire.beginTransmission(address) → Inicia uma transmissão para o dispositivo com o endereço especificado.
    Wire.write(data) → Envia um byte de dados para o dispositivo I2C.
    Wire.endTransmission() → Finaliza a transmissão de dados e libera o barramento I2C.
    Wire.available() → Retorna o número de bytes disponíveis para leitura.
    Wire.read() → Lê um byte de dados do dispositivo I2C.
    Wire.setClock(clockSpeed) → Ajusta a velocidade do barramento I2C, onde 'clockSpeed' pode ser, por exemplo, 100000 ou 400000.

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>



class I2C {
    private:
        uint8_t SDA;
        uint8_t SCL;
        int clockSpeed;

        
    public:
        I2C() = default;
        I2C(uint8_t SDA , uint8_t SCL);

        //Methods
        void begin(uint8_t address = 0);
        bool available();

        void requestFrom(uint8_t address, uint8_t quantity);

        void beginTransmission(uint8_t address);
        void endTransmission();

        void read();
        void write(uint8_t data);
        

        void setClock(int clockSpeed);

};