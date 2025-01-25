#include "../include/GPIO.hpp"


GPIO::GPIO(std::vector<int> digitalPins, std::vector<int> analogPins, std::vector<int> pwmPins)
{
    this->digitalPins = digitalPins;
    this->analogPins = analogPins;
    this->pwmPins = pwmPins;
}


/*void GPIO::setPortBit(volatile uint8_t &port, uint8_t pin, bool value)
{
    if (value)
    {
        port |= (1 << pin);
    }
    else
    {
        port &= ~(1 << pin);
    }
}

bool GPIO::isDigitalPin(uint8_t pin)
{
    for (int i = 0; i < 14; i++)
    {
        if (pin == digitalPins[i])
        {
            return true;
        }
    }
    return false;
}

bool GPIO::isAnalogPin(uint8_t pin)
{
    for (int i = 0; i < 6; i++)
    {
        if (pin == analogPins[i])
        {
            return true;
        }
    }
    return false;
}

bool GPIO::isConfiguredPin(uint8_t pin)
{
    return configuredPins[pin];
}

void GPIO::markAsConfiguredPin(uint8_t pin)
{
    configuredPins[pin] = true;
}

void GPIO::configurePort(uint8_t portRegister, uint8_t pin, bool mode)
{
    if (mode)
    {
        portRegister &= ~(1 << pin);
    }
    else
    {
        portRegister |= (1 << pin);
    }
}

void GPIO::configurePin(uint8_t pin, bool mode)
{
    if (isDigitalPin(pin))
    {
        // pinMode(pin, mode);
        markAsConfiguredPin(pin);

        if (pin >= 8 && pin <= 13)
        {
            configurePort(DDRB, pin - 8, mode);
        }
        else if (pin >= 0 && pin <= 7)
        {
            configurePort(DDRD, pin, mode);
        }
        else if (pin >= 14 && pin <= 19)
        {
            configurePort(DDRC, pin - 14, mode);
        }
    }
    else
    {
        printf("Erro");
        // Erro
    }
}

void GPIO::setup(uint8_t pin, bool stateOperative)
{
    this->configurePin(pin, stateOperative);
}

void GPIO::writeDigitalPin(uint8_t pin, bool stateOperative)
{
    if (this->isDigitalPin(pin))
    {
        if (pin >= 8 && pin <= 13)
        {
            setPortBit(PORTB, pin - 8, stateOperative);
        }
        else if (pin >= 0 && pin <= 7)
        {
            setPortBit(PORTD, pin, stateOperative);
        }
    }
    else
    {
        printf("Erro: Pino não é digital\n");
    }
}

// Função de leitura digital (simulada)
bool GPIO::readDigitalPin(uint8_t pin)
{
    if (isDigitalPin(pin))
    {
        if (pin >= 8 && pin <= 13)
        {
            return (PINB & (1 << (pin - 8))) != 0; // Lê o estado de PORTB
        }
        else if (pin >= 0 && pin <= 7)
        {
            return (PIND & (1 << pin)) != 0; // Lê o estado de PORTD
        }
        else if (pin >= 14 && pin <= 19)
        {
            return (PINC & (1 << (pin - 14))) != 0; // Lê o estado de PORTC
        }
    }
    printf("Erro: Pino digital inválido para leitura.\n");
    return false;
}

void GPIO::writeAnalogPin(uint8_t pin, bool stateOperative)
{
    if (this->isAnalogPin(pin))
    {
        if (pin >= 14 && pin <= 19)
        {
            setPortBit(PORTC, pin - 14, stateOperative);
        }
        // Aqui seria necessário adicionar o código para escrever valores analógicos via PWM.
        printf("Valor analógico escrito com sucesso.\n");
    }
    else
    {
        printf("Erro: Pino analógico inválido para escrita.\n");
    }
}

// Função de leitura analógica (simulada)
int GPIO::readAnalogPin(uint8_t pin)
{
    if (isAnalogPin(pin))
    {
        // Aqui seria necessário adicionar o código para ler valores analógicos via ADC.
        return 512; // Simulação de valor analógico
    }
    printf("Erro: Pino analógico inválido para leitura.\n");
    return -1;
}*/
