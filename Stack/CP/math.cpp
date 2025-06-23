#include <iostream>
#include <cmath>  // Include math.h (cmath in C++)

using namespace std;

int main() {
    // Variables for demonstration
    double number = 16.0;
    double base = 2.0;
    double exponent = 3.0;
    double angle = 45.0;  // in degrees

    // 1. Square root function (sqrt)
    double sqrtResult = sqrt(number);
    cout << "Square root of " << number << " is: " << sqrtResult << endl;

    // 2. Power function (pow)
    double powerResult = pow(base, exponent);
    cout << base << " raised to the power of " << exponent << " is: " << powerResult << endl;

    // 3. Sine function (sin) - angle should be in radians for trigonometric functions
    // Converting angle from degrees to radians
    double angleInRadians = angle * (M_PI / 180.0);
    double sineResult = sin(angleInRadians);
    cout << "Sine of " << angle << " degrees is: " << sineResult << endl;

    // 4. Cosine function (cos)
    double cosineResult = cos(angleInRadians);
    cout << "Cosine of " << angle << " degrees is: " << cosineResult << endl;

    // 5. Absolute value function (fabs)
    double negativeNumber = -9.5;
    double absResult = fabs(negativeNumber);
    cout << "Absolute value of " << negativeNumber << " is: " << absResult << endl;

    return 0;
}
