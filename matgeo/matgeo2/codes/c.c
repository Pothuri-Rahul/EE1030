#include <stdio.h>
#include <math.h>

int main() {
    // Define the circles
    double h1 = 1.0, k1 = 0.0, r1 = 1.0; // Circle 1: (x - h1)^2 + (y - k1)^2 = r1^2
    double h2 = 0.0, k2 = 0.0, r2 = 1.0; // Circle 2: x^2 + y^2 = r2^2

    // Calculate intersection points
    double x1 = (1.0 / 2.0); // Intersection x-coordinate
    double y1 = sqrt(r2 * r2 - x1 * x1); // Calculate y-coordinate for Circle 2
    double y2 = -y1; // Negative y-coordinate for Circle 2

    // Write the values to a file
    FILE *file = fopen("data.txt", "w");
    fprintf(file, "%.2f %.2f %.2f\n", h1, k1, r1); // Circle 1 parameters
    fprintf(file, "%.2f %.2f %.2f\n", h2, k2, r2); // Circle 2 parameters
    fprintf(file, "%.2f %.2f\n", x1, y1); // Intersection points
    fprintf(file, "%.2f %.2f\n", x1, y2);
    fclose(file);

    printf("Data written to data.txt\n");
    return 0;
}

