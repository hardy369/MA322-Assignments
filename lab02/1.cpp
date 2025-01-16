#include <iostream>
#include <cmath>
using namespace std;
double f(double x) {
    return tan(x) + tanh(x);
}

double bisection(double a, double b, double tol) {
    double c = a;  
    if (f(a)*f(b) >= 0) {
        cout << "Invalid initial interval. The function must have opposite signs at the endpoints.\n";
        return -1;
    }
while ((b - a) / 2.0 > tol) { 
 c = (a + b) / 2.0;//midpoint of a,b
if (f(c) == 0.0) {
break;
 }

 if (f(c)*f(a) < 0) {
b=c;  // The root lies in the left subinterval
} 
else {
a=c;  // The root lies in the right subinterval
}

}

return c; 
}

int main() { 
//choose a and b such that f(a)*f(b)<0
double a = 2;  // tan-1+tanh(-1) = -2.31900188061
double b = 3;  //tan0.5+tanh(0.5) = 1.0084196471
double tolerance = 1e-6;  
double root = bisection(a, b, tolerance);

if (root != -1) {
cout << "The smallest positive root is approximately " << root << endl;
}
return 0;
}

