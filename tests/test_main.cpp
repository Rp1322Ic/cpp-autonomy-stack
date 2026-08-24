#include <iostream>

void runVec2Tests();
void runVehicleStateTests();

int main(){
    std::cout << "Running unit tests ...\n";
    runVec2Tests();
    runVehicleStateTests();
    std::cout << "All unit tests passed!\n";

    return 0;
}