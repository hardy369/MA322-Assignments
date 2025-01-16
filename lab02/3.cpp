#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
// Define the function f(x) = x^3 - 4x - 9
double f(double x) {
return x*x*x - 4*x -9;
}

double regula_falsi(double a, double b, double tol) {
double c;  
int iteration = 0;
// Check that f(a) and f(b) have opposite signs
if (f(a) * f(b) > 0) {
 cerr << "Error: f(a) * f(b) >= 0. Invalid initial interval. The function must have opposite signs at the endpoints." << endl;
 return -1; 
 }
while (fabs(b - a) > tol) {
// Apply the Regula Falsi formula
c = b - (f(b) * (b - a)) / (f(b) - f(a));     
cout << "Iteration " << iteration + 1 << ": "<< "a = " << fixed << setprecision(6) << a << ", "<< "b = " << fixed << setprecision(6) << b << ", "<< "c = " << fixed << setprecision(6) << c << ", " << "f(c) = " << fixed << setprecision(6) << f(c) << endl;

 if (f(c) == 0) {
 return c; 
 }
if (f(c) * f(a) < 0) {
 b = c;  // Root lies in the left subinterval
} else {
  a = c;  // Root lies in the right subinterval
 }
 iteration++;
 if (iteration > 1000) {
cerr << "Error: Failed to converge." << endl;
 return -1;  
}
}
return c;  
}

int main() {  
double a = 2;  
double b = 3;  
double tolerance = 1e-6;
double root = regula_falsi(a, b, tolerance);

 if (root != -1) {
 cout << "\nThe root is: " << fixed << setprecision(6) << root << endl;
}
 return 0;
}

