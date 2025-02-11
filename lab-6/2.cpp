#include <iostream>
#include <cmath>

using namespace std;

// f(x) = e^x
double f(double x) {
    return exp(x);}

double centraldiff(double (*f)(double), double x, double h) {
    return (f(x+h)-f(x-h))/(2*h);}

double richardson(double (*f)(double), double x, double h) {
double d1 = centraldiff(f,x,h);
double d2 = centraldiff(f,x,2*h);
return d1 +((d1-d2)/ 3);
}

int main() {
double x = 1.0;
double exact = exp(x);
double h1 = 0.1;
double h2 = 0.05;
double centraldiff1 = centraldiff(f, x, h1);
double centraldiff2 = centraldiff(f, x, h2);
 double richardson1 = richardson(f, x, h1);
double richardson2 = richardson(f, x, h2);
    
    cout << "Exact derivative: " << exact << endl;
    cout << "Central Difference (h = 0.1): " << centraldiff1 << endl;
    cout << "Central Difference (h = 0.05): " << centraldiff2 << endl;
    cout << "Richardson Extrapolation (h = 0.1): " << richardson1 << endl;
    cout << "Richardson Extrapolation (h = 0.05): " << richardson2 << endl;
    
    // Compare the extrapolated results with the exact derivative
    cout << "Absolute Error (h = 0.1): " << fabs(richardson1 - exact) << endl;
    cout << "Absolute Error  (h = 0.05): " << fabs(richardson2 - exact) << endl;
    
    return 0;
}

