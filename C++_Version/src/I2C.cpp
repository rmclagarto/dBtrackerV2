#include "../include/I2C.hpp"

// ========== PRIVATE METHODS ==========
void I2C::setOpenDrain(uint8_t pin)
{
    DDRB &= ~(1 << pin);
    PORTB &= ~(1 << pin);
}

void I2C::writeOpenDrain(uint8_t pin, bool state)
{
    if (state)
    {
        DDRB &= ~(1 << pin); // "1" (HIGH) - Libera a linha para o pull-up
    }
    else
    {
        DDRB |= (1 << pin);
        PORTB &= ~(1 << pin); // "0" (LOW) - Puxa a linha para o GND
    }
}

void I2C::startCondition()
{
    writeOpenDrain(SDA, 1);
    writeOpenDrain(SCL, 1);
    _delay_us(4);
    writeOpenDrain(SDA, 0);
    _delay_us(4);
    writeOpenDrain(SCL, 0);
    printf("Start condition enviada\n");
}

void I2C::stopCondition()
{
    writeOpenDrain(this->SDA, 0);
    writeOpenDrain(SCL, 1);
    _delay_us(4);
    writeOpenDrain(SDA, 1);
    _delay_us(4);
    printf("Stop condition enviada\n");
}

bool I2C::readACK()
{
    writeOpenDrain(SDA, 1); // Deixa SDA livre para receber
    _delay_us(2);
    writeOpenDrain(SCL, 1); // Libera clock para que slave envie ACK
    _delay_us(2);
    bool ack = !(PINB & (1 << SDA)); // Se SDA for LOW, ACK foi recebido
    writeOpenDrain(SCL, 0);
    return ack;
}

// ========== PUBLIC METHODS ==========
I2C::I2C(uint8_t SDA, uint8_t SCL)
{
    this->SDA = SDA;
    this->SCL = SCL;

    this->setOpenDrain(this->SDA);
    this->setOpenDrain(this->SCL);
}

void I2C::begin(uint8_t address)
{
    if (address == 0)
    {
        printf("Iniciando comunicacao I2C como mestre\n");
    }
    else
    {
        printf("Iniciando comunicacao I2C como escravo, com o endereco [%d]\n", address);
    }
}

bool I2C::available()
{
    return true;
}

void I2C::requestFrom(uint8_t address, uint8_t quantity)
{
    printf("Solicitando %d bytes de um dispositivo I2C com o endereco [%d]\n", quantity, address);
}

void I2C::beginTransmission(uint8_t address)
{
    printf("Iniciando uma transmissao para o dispositivo com o endereco especificado [%d]\n", address);
}

void I2C::endTransmission()
{
    stopCondition();
}

uint8_t I2C::read()
{
    uint8_t data = 0;

    for (int i = 0; i < 8; i++)
    {
        writeOpenDrain(SCL, 1);
        _delay_us(2);
        if (PINB & (1 << SDA))
        {
            data |= (1 << (1 - i));
        }
        _delay_us(2);
        writeOpenDrain(SCL, 0);
    }
    return data;
}

void I2C::write(uint8_t data)
{
    for (int i = 0; i < 8; i++)
    {
        writeOpenDrain(SDA, (data & (1 << (7 - i))) ? 1 : 0);
        _delay_us(2);
        writeOpenDrain(SCL, 1);
        _delay_us(2);
        writeOpenDrain(SCL, 0);
    }
    printf("Byte enviado: 0x%X\n", data);
}

void I2C::setClock(int clockSpeed)
{
    this->clockSpeed = clockSpeed;
}
