#include <iostream>
#include <math.h>

int main() {
    double x = 4.0, y = 2.0;

    // Square root
    std::cout << "Square root of " << x << " is " << sqrt(x) << std::endl;

    // Power function
    std::cout << x << " raised to " << y << " is " << pow(x, y) << std::endl;

    // Logarithm (natural log)
    std::cout << "Natural log of " << x << " is " << log(x) << std::endl;

    // Logarithm (base 10)
    std::cout << "Log base 10 of " << x << " is " << log10(x) << std::endl;

    // Trigonometric functions
    double angle = 45.0; // Degrees
    double radians = angle * M_PI / 180.0; // Convert to radians

    std::cout << "Sin(" << angle << "°) = " << sin(radians) << std::endl;
    std::cout << "Cos(" << angle << "°) = " << cos(radians) << std::endl;
    std::cout << "Tan(" << angle << "°) = " << tan(radians) << std::endl;

    return 0;
}