#include "VehicleState.hpp"
#include <cmath>
#include <algorithm>

VehicleState::VehicleState(double wheelbaseLength)
    : position(0.0,0.0), heading(0.0), speed(0.0), wheelbase(wheelbaseLength)
{
}

VehicleState::VehicleState(const Vec2& initialPos, double initialHeading, double initialspeed, double wheelbaseLength)
    : position(initialPos), heading(initialHeading), speed(initialspeed), wheelbase(wheelbaseLength)
{
}

double VehicleState::normalizeAngle(double angleRad){
    return std::atan2(std::sin(angleRad), std::cos(angleRad));
}


void VehicleState::update(ControlInput input, double dt){
    speed += input.acceleration * dt;
    
    speed = std::max(0.0, speed);

    heading += speed/wheelbase * std::tan(input.steeringAngle) * dt;

    position.x += speed * std::cos(heading) * dt;
    position.y += speed * std::sin(heading) * dt;

    heading = normalizeAngle(heading);
}

