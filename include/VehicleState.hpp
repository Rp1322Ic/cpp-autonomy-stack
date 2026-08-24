#pragma once
#include "Vec2.hpp" // Utilizing your existing Vec2 class
#include "ControlInput.hpp" 

class VehicleState {
private:
    Vec2 position;
    double heading;
    double speed; 
    
    const double wheelbase; 

    
public:
    // Constructors
    VehicleState(double wheelbaseLength);
    VehicleState(const Vec2& initialPos, double initialHeading, double initialSpeed, double wheelbaseLength);

    // Getters
    Vec2 getPosition() const { return position; }
    double getHeading() const { return heading; }
    double getSpeed() const { return speed; }
    double getWheelbase() const { return wheelbase; }

    // Setters 
    void setSpeed(double newSpeed) { speed = newSpeed; }

    // Methods
    void update(const ControlInput& input, double dt);

    static double normalizeAngle(double angleRad);
    
};
