# C++ Autonomy Stack

A modular C++ autonomy simulation project for a 2D ground vehicle.

This project is being built to develop practical robotics/autonomy software skills in modern C++. The current version implements a kinematic vehicle model, trajectory generation, CSV logging, lightweight unit tests, and Python-based visualisation. The long-term goal is to extend this into a small autonomy stack with noisy sensors, state estimation, path planning, and path-following control.

## Current Features

* Modern C++ project structure using CMake
* `Vec2` 2D vector utility type
* `ControlInput` struct for vehicle commands
* `VehicleState` class representing vehicle position, heading, speed, and wheelbase
* Kinematic bicycle-style vehicle update
* CSV trajectory export
* Python animation script for visualising vehicle motion
* Lightweight assert-based unit tests

## Planned Features

The project is being developed incrementally. Planned extensions include:

* Noisy GPS sensor model
* Noisy odometry / speed sensor model
* True trajectory vs measured trajectory visualisation
* Dead-reckoning estimator
* Extended Kalman Filter
* A* path planning on a 2D grid map
* PID path-following controller
* LQR controller comparison
* Obstacle avoidance
* Optional multi-agent simulation extension

## Project Structure

```text
cpp-autonomy-stack/
├── CMakeLists.txt
├── include/
│   ├── ControlInput.hpp
│   ├── Vec2.hpp
│   └── VehicleState.hpp
├── src/
│   ├── main.cpp
│   ├── Vec2.cpp
│   └── VehicleState.cpp
├── tests/
│   ├── test_main.cpp
│   ├── test_vec2.cpp
│   └── test_vehicle_state.cpp
├── scripts/
│   └── animate_car.py
├── data/
│   └── trajectory.csv
├── visualisation/
│   └── vehicle_kinematics.gif
└── README.md
```

Generated files such as CSV outputs and GIFs may be ignored by Git depending on the local `.gitignore` setup.

## Vehicle Model

The current simulator uses a simple kinematic bicycle-style model. The vehicle state contains:

* position in the world frame
* heading angle
* scalar forward speed
* wheelbase length

The control input contains:

* steering angle
* longitudinal acceleration

At each timestep, the simulator updates the vehicle speed, heading, and position based on the current state and control input.

This is intentionally a kinematic model rather than a full dynamic model with mass, inertia, tyre forces, and slip angles. The purpose of this first stage is to build a clean and testable autonomy software foundation before increasing model fidelity.

## Build Instructions

From the project root:

```bash
mkdir -p build
cd build
cmake ..
cmake --build .
```

This builds two executables:

```text
autonomy_sim
unit_tests
```

## Running the Simulator

From the `build/` directory:

```bash
./autonomy_sim
```

The simulator writes trajectory data to:

```text
data/trajectory.csv
```

The current CSV output contains:

```text
time,x,y,heading,speed
```

## Running Unit Tests

From the `build/` directory:

```bash
./unit_tests
```

The unit tests currently cover:

* `Vec2` construction
* vector addition
* vector subtraction
* scalar multiplication
* vector norm and squared norm
* default vehicle construction
* parameterised vehicle construction
* acceleration behaviour
* circular motion behaviour

## Visualising the Trajectory

After running the simulator, run the Python visualisation script from the project root:

```bash
python scripts/animate_car.py
```

This reads:

```text
data/trajectory.csv
```

and writes:

```text
visualisation/vehicle_kinematics.gif
```

## Development Philosophy

This project is being built step by step, with emphasis on:

* writing C++ manually
* understanding the underlying autonomy concepts
* using clean object-oriented design
* keeping each milestone compiling and testable
* adding complexity only after the foundation is stable

The current focus is on building a reliable simulation core. The next major step is to add noisy sensors, starting with GPS, so that the project begins to resemble a real autonomy pipeline:

```text
true vehicle state
→ noisy sensor measurements
→ state estimation
→ planning
→ control
→ vehicle update
```

## Current Status

This project is in active development.

Current milestone:

```text
Kinematic vehicle simulator with unit tests and trajectory visualisation.
```

Next milestone:

```text
Add noisy GPS measurements and plot true trajectory versus measured trajectory.
```
