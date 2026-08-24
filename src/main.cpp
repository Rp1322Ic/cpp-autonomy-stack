#include "VehicleState.hpp"
#include <iostream>
#include <fstream>
#include <cmath>

void runSimulationAndExport() {
    std::cout << "[SIMULATION] Running vehicle trajectory generator...\n";
    double T = 10.0;
    double dt = 0.1;
    double thetadot = 2*std::acos(-1.0)/T;
    double initialHeading = std::acos(-1.0) / 2.0;
    double w = 2.5;
    double steeringInput = 10.0*std::acos(-1.0)/180;     
    double accelerationInput = 0.0;  
    
    double v = thetadot*w/std::tan(steeringInput);

    VehicleState car({0.0, 0.0}, initialHeading, v, w);
    ControlInput ctrlInputs{steeringInput,accelerationInput};

    int N = std::ceil(T/dt);

    // // Setup: 2.5m wheelbase car starting at origin, facing North (pi / 2)
    // double initialHeading = std::acos(-1.0) / 2.0;
    // VehicleState car({0.0, 0.0}, initialHeading, 10.0, 2.5);

    // double steeringInput = 10.0;     
    // double accelerationInput = 0.0;  
    // double dt = 0.1;

    // ControlInput ctrlInputs{steeringInput,accelerationInput};

    std::ofstream csvFile("data/trajectory.csv");
    if (!csvFile.is_open()) {
        std::cerr << "Error: Could not create trajectory.csv\n";
        return;
    }

    csvFile << "time,x,y,heading,speed\n";

    // int T = 10;
    // int N = T/dt;
    for(int i = 0; i <= N; ++i) {
        double time = i * dt;
        csvFile << time << "," 
                << car.getPosition().x << "," 
                << car.getPosition().y << "," 
                << car.getHeading() << "," 
                << car.getSpeed() << "\n";
        
        car.update(ctrlInputs, dt);
    }

    csvFile.close();
    std::cout << "[SIMULATION] Successfully exported 250 states to trajectory.csv\n";
}

int main() {
    std::cout << "========================================\n";
    std::cout << "Autonomous Vehicle Codebase - Step 3 (Full Circle)\n";
    std::cout << "========================================\n";

    runSimulationAndExport();
    return 0;
}
