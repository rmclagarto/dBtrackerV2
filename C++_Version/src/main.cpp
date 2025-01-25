#include <microcontroller.hpp>


int main(void){
    try{
        Microcontroller microMaster("ARDUINO_UNO");
        
        printf("%d\n",microMaster.I2Cwrite(0x50));

        while(1);

    }catch(const std::runtime_error& e){
        std::cout <<"Error: " << e.what() << std::endl;
    }
    return 0;
}