#pragma once

/*
    SPI.begin() → Inicia a comunicação SPI.
    SPI.beginTransaction(SPISettings(speed, bitOrder, dataMode)) → Configura a transação SPI com a velocidade, ordem de bits e modo de dados.
    SPI.transfer(data) → Envia e recebe um byte de dados via SPI.
    SPI.endTransaction() → Finaliza a transação SPI.
    SPI.end() → Encerra a comunicação SPI.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

class SPI{
    private:
        uint8_t MOSI;
        uint8_t MISO;
        uint8_t SCK;
        uint8_t SS;

    public:
        SPI() = default;
        SPI(uint8_t MOSI, uint8_t MISO, uint8_t SCK, uint8_t SS);

        void begin();
        void beginTransaction();
        void transfer();
        void endTransaction();
        void end();

};