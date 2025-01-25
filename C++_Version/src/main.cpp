#include "../include/microcontroller.hpp"


int main(void){
    try{
        Microcontroller micro("ARDUINO_UNO");
        micro.I2Cbegin(0x68);

        

    }catch(const std::runtime_error& e){
        std::cout <<"Error: " << e.what() << std::endl;
    }
    
    return 0;
}