#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

void periodicCubicSplineInterpolation(const vector<double>& x, const vector<double>& y) {
int n = x.size() - 1;  

double h = 1.0; //since periodic 

vector<double> alpha(n);
 for (int i=1;i<n;i++) {
alpha[i] = (3.0/h)*(y[i+1]-y[i])-(3.0/h)*(y[i]-y[i-1]);
}
vector<double> l(n + 1, 1.0), mu(n), z(n + 1, 0.0);
for (int i = 1; i < n; i++) {
l[i] =2.0*(x[i + 1]-x[i - 1])-h*mu[i - 1];
mu[i] = h/l[i];
z[i] = (alpha[i]-h*z[i - 1])/l[i];
}
l[n] = 2.0*(x[1] - x[n - 1])-h*mu[n - 1];
mu[n] = h/l[n];
z[n] = (alpha[0]-h*z[n - 1])/l[n];

vector<double> M(n + 1, 0.0);
for (int i = n - 1; i >= 0; i--) {
M[i] = z[i] - mu[i] * M[i + 1];
}

vector<double> A(n), B(n), C(n), D(n);
for (int i = 0; i < n; i++) {
A[i] = y[i];
B[i] = (y[i + 1] - y[i]) / h - h * (M[i + 1] + 2 * M[i]) / 3.0;
C[i] = M[i] / 2.0;
D[i] = (M[i + 1] - M[i]) / (3.0 * h);
}
/*
cout << fixed << setprecision(4);
cout << "Cubic Spline Coefficients:" << endl;
for (int i = 0; i < n; i++) {
cout << "S" << i << "(x) = " << A[i] << " + " << B[i] << "(x - " << x[i] << ") + " << C[i] << "(x - " << x[i] << ")^2 + " << D[i] << "(x - " << x[i] << ")^3" << endl;
} */
   vector<double> x_test = {1.25, 1.70,3.5,4.25}; 
 for(int j=0;j< x_test.size();j++ ){
 double test_x =x_test [j];
int i = 0;
while (i < n && x[i + 1] < test_x) i++; 
double result = A[i] + B[i] * (test_x - x[i]) + C[i] * pow(test_x - x[i], 2) + D[i] * pow(test_x - x[i], 3);
cout << "interpolated value ynew at x = " << test_x << " is: " << result << endl;
}
}
int main() {
  
    vector<double> x = {1.0, 2.0, 3.0, 4.0,5.0};
    vector<double> y = {2.0,8.0,18.0,32.0,50.0};

periodicCubicSplineInterpolation(x, y);

    return 0;
}

