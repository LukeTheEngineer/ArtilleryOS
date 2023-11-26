#include "./include/math.h"

// Trigonometry functions
// Helper function to reduce angles to the range [-PI, PI]
static double reduce_angle(double angle)
{
	while (angle > PI) {
		angle -= TWO_PI;
	}
	while (angle < -PI) {
		angle += TWO_PI;
	}
	return angle;
}

// Taylor series expansion for sine function
double sin(double x)
{
	x = reduce_angle(x);

	return x - (x * x * x) / 6.0 + (x * x * x * x * x) / 120.0 -
	       (x * x * x * x * x * x * x) / 5040.0;
}

// Taylor series expansion for cosine
double cos(double x)
{
	x = reduce_angle(x);

	return 1.0 - (x * x) / 2.0 + (x * x * x * x) / 24.0 -
	       (x * x * x * x * x * x) / 720.0;
}

// Tangent calculation
double tan(double x)
{
	return sin(x)/cos(x);
}

// Taylor series expansion for inverse sine function (arcsin)
double arcsin(double x)
{
    return x + ( (exp(x, 3))/factorial(3) ) + (( 1 * 3 * exp(x, 5)) / 40.0 ) + ( ( 1 * 3 * 5 * exp(x, 7) ) / 384.0 );
}

// Factorial
int factorial(int n)
{
    int result = n;

    if (n == 0)
    {
	return 1;
    }

    while (n != 1)
    {
	result = result*(n-1);
	n--;
    }

    return result;
}

// Exponentiation
double exp(double b, double n)
{
    double result = 1.0;
    while (n != 0)
    {
	result *= b;
	n--;
    }
    return result;
}

// Square root
double sqrt(double x)
{
   return exp(x, 0.5); 
}
