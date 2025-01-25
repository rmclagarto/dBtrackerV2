#include "../include/I2C.hpp"


//Public


I2C::I2C(uint8_t SDA , uint8_t SCL){
    this->SDA = SDA;
    this->SCL = SCL;
}


void I2C::begin(uint8_t address){
    if(address == 0){
        printf("Iniciando comunicacao I2C como mestre\n");
    }else{
        printf("Iniciando comunicacao I2C como escravo, com o endereco [%d]\n", address);
    }
}


bool I2C::available(){
    return false;
}

void I2C::requestFrom(uint8_t address, uint8_t quantity){
    printf("Solicitando %d bytes de um dispositivo I2C com o endereco [%d]\n", quantity, address);
}

void I2C::beginTransmission(uint8_t address){
    printf("Iniciando uma transmissao para o dispositivo com o endereco especificado [%d]\n", address);
}

void I2C::endTransmission(){
    printf  ("Finalizando a transmissao de dados e liberando o barramento I2C\n");
}

void I2C::read(){
    printf("Lendo um byte de dados do dispositivo I2C\n");
}

void I2C::write(uint8_t data){
    printf("Enviando um byte de dados para o dispositivo I2C\n");
}

void I2C::setClock(int clockSpeed){
    this->clockSpeed = clockSpeed;
}

