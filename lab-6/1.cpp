#include <iostream>
#include <cmath>
#include <vector>
#include <functional>
using namespace std;
double trapezoidal(function<double(double)> f, double a, double b, int n) {
double h = (b-a)/(n-1);
double sum = 0.5*(f(a)+f(b));
 for (int i=1;i<n-1;++i) {
sum += f(a+i*h);
}
return sum*h;
}


double simpsons(function<double(double)> f, double a, double b, int n) {
double h = (b-a)/(n-1);
double sum = f(a)+f(b);
    
    for (int i=1;i<n-1;++i) {
        if (i%2 == 0) {
            sum +=2*f(a+i*h); 
        } else {
            sum += 4*f(a+i*h); 
        }
    }
    
    return sum*h/3;
}


function<double(double)> f(int p) {
    return [p](double x) {
        return pow(x, p) / (pow(x, 3) + 10);
    };
}

int main() {
    double a = 0.0;
    double b = 1.0;
    vector<int> p_values = {0, 1}; 
    vector<int> n_points = {11, 21, 41}; 
    
for (int p : p_values) {
cout << "Results for p = " << p << ":\n";
 // Create the integrand function based on p
function<double(double)> f = f(p);
for (int n : n_points) {
double trap = trapezoidal(f, a, b, n);
double simp = simpsons(f, a, b, n);
 cout << "  For n = " << n << " points:\n";
 cout << "    Trapezoidal Rule: " << trap << endl;
cout << "    Simpson's Rule: " << simp << endl;
}
  cout << endl;
}  return 0;
}

