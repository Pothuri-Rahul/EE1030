import numpy as np
from scipy.integrate import quad
from scipy.optimize import fsolve

# Circle parameters
h1, k1, r1 = 1, 0, 1  # Circle 1: (x - 1)^2 + y^2 = 1
h2, k2, r2 = 0, 0, 1  # Circle 2: x^2 + y^2 = 1

# Define the equations for the circles
def circle1_upper(x):
    return np.sqrt(r1**2 - (x - h1)**2) + k1

def circle1_lower(x):
    return -np.sqrt(r1**2 - (x - h1)**2) + k1

def circle2_upper(x):
    return np.sqrt(r2**2 - (x - h2)**2) + k2

def circle2_lower(x):
    return -np.sqrt(r2**2 - (x - h2)**2) + k2

# Find points of intersection
def find_intersections():
    def eq(x):
        return circle1_upper(x) - circle2_upper(x)

    # Finding intersection points
    x_intersect = fsolve(eq, [0.5])  # Initial guess near the expected intersection
    return x_intersect

x_int = find_intersections()

# Compute area between the circles
def area_between_circles(x):
    return circle1_upper(x) - circle2_upper(x)

# Integrate the area between the intersection points
area, _ = quad(area_between_circles, x_int[0], x_int[1])

print(f"Area enclosed between the circles: {area:.4f}")

