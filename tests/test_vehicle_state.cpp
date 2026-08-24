#include "VehicleState.hpp"

#include <cassert>
#include <cmath>
#include <iostream>

bool approxEqual(double a, double b, double tolerance = 1e-6);

void testDefaultConstructorVehicleState() {
    double wheelbaseIn = 2.5;
    VehicleState car(wheelbaseIn);
    
    assert(approxEqual(car.getPosition().x,0.0));
    assert(approxEqual(car.getPosition().y,0.0));
    assert(approxEqual(car.getHeading(),0.0));
    assert(approxEqual(car.getSpeed(),0.0));
    assert(approxEqual(car.getWheelbase(),wheelbaseIn));
}

void testConstructorVehicleState() {
    double xIn = 5.0;
    double yIn = -2.7;
    double headingIn = 10.5;
    double speedIn = 0.001;
    double wheelbaseIn = 2.5;

    VehicleState car({xIn,yIn},headingIn,speedIn,wheelbaseIn);
    
    assert(approxEqual(car.getPosition().x,xIn));
    assert(approxEqual(car.getPosition().y,yIn));
    assert(approxEqual(car.getHeading(),headingIn));
    assert(approxEqual(car.getSpeed(),speedIn));
    assert(approxEqual(car.getWheelbase(),wheelbaseIn));
}

void testAcceleration(){
    double initialHeading = std::acos(-1.0) / 2.0;
    VehicleState car({0.0, 0.0}, initialHeading, 0.0, 2.5);

    double steeringInput = 0.0;     
    double accelerationInput = 1.0;  
    double dt = 0.1;

    ControlInput ctrlInputs{steeringInput,accelerationInput};

    int T = 10;
    int N = T/dt;
    for(int i = 0; i < N; ++i) {
        car.update(ctrlInputs, dt);
    }
    assert(approxEqual(car.getPosition().x, 0.0));
    assert(approxEqual(car.getPosition().y, 50.5));
    assert(approxEqual(car.getHeading(), initialHeading));
    assert(approxEqual(car.getSpeed(), accelerationInput*T));
}

void testCircularMotion(){
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
    for(int i = 0; i < N; ++i) {
        car.update(ctrlInputs, dt);
    }
    assert(approxEqual(car.getPosition().x, 0));
    assert(approxEqual(car.getPosition().y, 0));
    assert(approxEqual(car.getHeading(), initialHeading));
    assert(approxEqual(car.getSpeed(), v));
}

void runVehicleStateTests() {
    testDefaultConstructorVehicleState();
    testConstructorVehicleState();
    testAcceleration();
    testCircularMotion();
    std::cout << "VehicleState Tests Passed!\n";
}