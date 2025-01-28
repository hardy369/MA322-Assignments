#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double f(double x) {
return exp(-x)*(x*x + 5*x + 2) + 1;
}

double secant(double x0, double x1, double tol) {
double x2;
int iteration = 0;
while (fabs(x1-x0) > tol) {
x2 = x1 - (f(x1)*(x1-x0)) / (f(x1)-f(x0));
cout << "Iteration " << iteration + 1 << " x0 = " << fixed << setprecision(6) << x0
<< ", x1 = " << fixed << setprecision(6) << x1 << ", x2 = " << fixed << setprecision(6) << x2 << ", f(x2) = " << fixed << setprecision(6) << f(x2) << endl;

x0 = x1;
x1 = x2;
iteration++;
}
return x2;
}

int main() {
double x0 = -1.5;
double x1 = -3.0;
double tolerance = 1e-6;
double root = secant(x0, x1, tolerance);
cout << "\nThe root is: " << fixed << setprecision(6) << root << endl;
return 0;
}

