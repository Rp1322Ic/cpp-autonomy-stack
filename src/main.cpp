#include "VehicleState.hpp"
#include <iostream>
#include <fstream>
#include <cmath>

void runSimulationAndExport() {
    std::cout << "[SIMULATION] Running vehicle trajectory generator...\n";

    // Setup: 2.5m wheelbase car starting at origin, facing North (pi / 2)
    double initialHeading = std::acos(-1.0) / 2.0;
    VehicleState car({0.0, 0.0}, initialHeading, 0.0, 2.5);

    double steeringInput = 0.0;     // Constant steering wheel angle (rad)
    double accelerationInput = 1.0;  // Maintain constant speed
    double dt = 0.1;                 // 100ms time-step

    std::ofstream csvFile("data/trajectory.csv");
    if (!csvFile.is_open()) {
        std::cerr << "Error: Could not create trajectory.csv\n";
        return;
    }

    csvFile << "time,x,y,heading,speed\n";

    int T = 10;
    int N = T/dt;
    for(int i = 0; i <= N; ++i) {
        double time = i * dt;
        csvFile << time << "," 
                << car.getPosition().x << "," 
                << car.getPosition().y << "," 
                << car.getHeading() << "," 
                << car.getSpeed() << "\n";
        
        car.update(steeringInput, accelerationInput, dt);
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
