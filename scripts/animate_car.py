import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

# 1. Load the simulated kinematics data from the C++ file
try:
    data = pd.read_csv('data/trajectory.csv')
except FileNotFoundError:
    print("Error: trajectory.csv not found! Run the C++ program first.")
    exit()

# 2. Setup the plot window
fig, ax = plt.subplots(figsize=(8, 8))
ax.set_title("Autonomous Vehicle Kinematics Model Verification", fontsize=14)
ax.set_xlabel("Global X Position (m)", fontsize=11)
ax.set_ylabel("Global Y Position (m)", fontsize=11)
ax.grid(True, linestyle='--', alpha=0.6)


# Dynamically pad limits based on the complete circle boundaries
ax.set_xlim(data['x'].min() - 5, data['x'].max() + 5)
ax.set_ylim(data['y'].min() - 5, data['y'].max() + 5)

ax.set_aspect('equal', adjustable='box')

# Graph visual elements
path_line, = ax.plot([], [], 'b--', label='Vehicle Path', alpha=0.7)

initial_x = data['x'].iloc[0]
initial_y = data['y'].iloc[0]
initial_heading = data['heading'].iloc[0]

initial_u = np.cos(initial_heading) * 1.5
initial_v = np.sin(initial_heading) * 1.5

car_marker = ax.quiver(
    initial_x,
    initial_y,
    initial_u,
    initial_v,
    color='red',
    angles='xy',
    scale_units='xy',
    scale=1,
    label='Vehicle Axle'
)

ax.legend(loc='upper right')

# 3. Animation update function run for each frame
def update(frame):
    x_history = data['x'].iloc[:frame + 1]
    y_history = data['y'].iloc[:frame + 1]

    path_line.set_data(x_history, y_history)

    current_x = data['x'].iloc[frame]
    current_y = data['y'].iloc[frame]
    current_heading = data['heading'].iloc[frame]

    u = np.cos(current_heading) * 1.5
    v = np.sin(current_heading) * 1.5

    car_marker.set_offsets([[current_x, current_y]])
    car_marker.set_UVC(u, v)

    return path_line, car_marker

# 4. Generate dynamic animation
ani = FuncAnimation(fig, update, frames=len(data), interval=100, blit=False, repeat=False)

# Save the animation as a GIF file instead of trying to open an interactive window
output_filename = "visualisation/vehicle_kinematics.gif"
print(f"[VISUALISER] Processing frames and saving to {output_filename}...")

ani.save(output_filename, writer='pillow', fps=10)

print(f"[VISUALISER] Render complete! You can now open {output_filename} to see the animation.")