#include <iostream>
#include <cmath>
#include <limits>
using namespace std;
double f(double x){
return pow(x, 4) - 6 * pow(x, 3) + 11 * pow(x, 2) - 6 * x + 1;}

double f_prime(double x){
return 4 * pow(x, 3) - 18 * pow(x, 2) + 22 * x - 6;}

double f_double_prime(double x){
return 12 * pow(x, 2) - 36 * x + 22;}

double mullermethod(double x0, double x1, double x2, double tolerance){
int iteration = 0;

while (true){
 double f0 = f(x0);
 double f1 = f(x1);
 double f2 = f(x2);  
 double h0 = x1 - x0;
 double h1 = x2 - x1;
 double delta0 = (f1 - f0) / h0;
double delta1 = (f2 - f1) / h1;
double a = (delta1 - delta0) / (h1 + h0);
double b = delta1 + h1 * a;
double c = f2;
double D = b*b - 4.0 * a *c;
if (D < 0){
   cout << "Complex root encountered; skipping..." << endl;
  break;}
double root1 = (x2 )+  (-2.0 * c) /(b+D);
double root2 = (x2 )+  (-2.0 * c) /(b-D);
double next_root = (abs(root1 - x2) < abs(root2 - x2)) ? root1 : root2;
if (abs(next_root - x2) < tolerance){break;}
x0 = x1;
x1 = x2;
x2 = next_root;
iteration++;}
return x2; 
}
int main(){
    double x0 =0.5, x1 = 1.0, x2 = 2.0;
    double tolerance = 1e-6;
    double root = mullermethod(x0, x1, x2, tolerance);
    cout << "Found root: " << root << endl;
    return 0;
}

