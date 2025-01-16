#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
// This code is the same as the 3.cpp but it breaks the loop once the f(c) coverges to 0 upto 6 decimal points.
double f(double x) {
return x*x*x - 4*x - 9;
}

double regula_falsi(double a, double b, double tol) {
double c;
int iteration = 0;
 if (f(a) * f(b) > 0) {
cerr << "Error: f(a) * f(b) >= 0.Invalid initial interval. The function must have opposite signs at the endpoints." << endl;
  return -1; 
 }
 while (fabs(b - a) > tol) {
 c = b - (f(b) * (b - a)) / (f(b) - f(a));     
cout << "Iteration " << iteration + 1 << ": " << "a = " << fixed << setprecision(6) << a << ", "<< "b = " << fixed << setprecision(6) << b << ", "<< "c = " << fixed << setprecision(6) << c << ", "<< "f(c) = " << fixed << setprecision(6) << f(c) << endl;
if (fabs(f(c)) <= tol*0.1)         // Check if f(c) is close enough to 0 (to 6 decimal places)
{ cout << "\nThe root is: " << fixed << setprecision(6) << c << "f(c) = " << fixed << setprecision(6) << f(c) << endl;
return c;  
 }
if (f(c) * f(a) < 0) {
b = c;  // Root lies in the left subinterval
} else {
 a = c;  // Root lies in the right subinterval
}
 iteration++;
if (iteration > 1000) {
cerr << "Error: Maximum number of iterations reached without convergence." << endl;
return -1;  
}
}  // Return the last value of c if the loop finishes without convergence
return c;  
}

int main() {
double a = 2;  
double b = 3;  
double tol = 1e-6;
double root = regula_falsi(a, b, tol);
if (root != -1) {
cout << "\nThe root is: " << fixed << setprecision(6) << root << endl;
}
return 0;
}

