import numpy as np
import matplotlib.pyplot as plt

# Define the figure and axis
fig, ax = plt.subplots(figsize=(6, 6))

# Parameters for the circles
circle1_center = (1, 0)
circle2_center = (0, 0)
radius = 1

# Create circles
circle1 = plt.Circle(circle1_center, radius, color='orange', fill=False, linewidth=2)
circle2 = plt.Circle(circle2_center, radius, color='blue', fill=False, linewidth=2)

# Add the circles to the plot
ax.add_artist(circle1)
ax.add_artist(circle2)

# Define theta for parameterizing the circles
theta = np.linspace(0, 2 * np.pi, 500)

# Circle 1: (x - 1)^2 + y^2 = 1
x1 = circle1_center[0] + radius * np.cos(theta)
y1 = circle1_center[1] + radius * np.sin(theta)

# Circle 2: x^2 + y^2 = 1
x2 = circle2_center[0] + radius * np.cos(theta)
y2 = circle2_center[1] + radius * np.sin(theta)

# Plot the circles
ax.plot(x1, y1, color='orange')
ax.plot(x2, y2, color='blue')

# Define the intersection points
# The intersection points of the circles can be found by solving the equations:
# (x - 1)^2 + y^2 = 1 and x^2 + y^2 = 1
# This gives the points (0.5, ±√(0.75))

y_intersection = np.sqrt(0.75)
intersection_points = [(0.5, y_intersection), (0.5, -y_intersection)]

# Fill the intersection area
y_fill = np.linspace(-y_intersection, y_intersection, 500)
x_fill1 = 1 - np.sqrt(1 - y_fill**2)  # From circle 1
x_fill2 = np.sqrt(1 - y_fill**2)      # From circle 2

# Fill between the two curves in the intersection area
ax.fill_betweenx(y_fill, x_fill1, x_fill2, where=(x_fill2 >= x_fill1), color='cyan', alpha=0.5)

# Set axis limits and aspect ratio
ax.set_xlim(-1.5, 2)
ax.set_ylim(-1.5, 1.5)
ax.set_aspect('equal')

# Set labels
ax.set_xlabel('x-axis')
ax.set_ylabel('y-axis')
ax.set_title('Intersection of Two Circles')

# Add grid for better visualization
ax.grid(True)

# Save the plot as a PNG file
plt.savefig('intersection_of_circles.png', dpi=300, bbox_inches='tight')

# Show the plot
plt.show()

