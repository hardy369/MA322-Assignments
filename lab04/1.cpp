#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;


double f(double x) {
if (x == 0) return 1;  // function is undefined at 0
return sin(x) / (x * x);
}


double lagrangeInterpolation(const vector<double>& x_vals, const vector<double>& y_vals, double x) {
 double result = 0.0;
int n = x_vals.size();
 for (int i=0;i<n;++i) {
double term = y_vals[i];
 for (int j=0; j<n;++j) {
if (i!=j) {term *= (x - x_vals[j]) / (x_vals[i] - x_vals[j]);
}
}
result += term;
}
return result;
}

double newtonInterpolation(const vector<double>& x_vals, const vector<double>& y_vals, double x) {
int n = x_vals.size();
vector<vector<double>> divided_diff(n, vector<double>(n));
 for (int i = 0; i < n; ++i) {
divided_diff[i][0] = y_vals[i];
}
for (int j=1; j<n; ++j) {
for (int i=0; i<n-j;++i) {
divided_diff[i][j] =(divided_diff[i + 1][j - 1] - divided_diff[i][j - 1]) / (x_vals[i + j] - x_vals[i]);
}}

double result = divided_diff[0][0];
double term = 1.0;
for (int i = 1; i < n; ++i) {
term *= (x - x_vals[i - 1]);
result += divided_diff[0][i] * term;
}
return result;
}

int main() {
double x0 = 0.1, xn = 1.0;
int n = 10; //change n here to change the intervals
double h = (xn - x0) / (n - 1);

vector<double> x_vals(n), y_vals(n);
for (int i = 0; i < n; ++i) {
x_vals[i] = x0 + i * h;
y_vals[i] = f(x_vals[i]);}
 cout << "x\tf(x)" << endl;
for (int i = 0; i < n; ++i) {
cout << fixed << setprecision(4) << x_vals[i] << "\t" << f(x_vals[i]) << endl;
}
cout << "\nInterpolated Values and Errors:" << endl;
for (int i = 1; i < n - 1; ++i) {
double x_mid = 0.5 * (x_vals[i] + x_vals[i + 1]); //mid points
double P_lagrange = lagrangeInterpolation(x_vals, y_vals, x_mid);
double P_newton = newtonInterpolation(x_vals, y_vals, x_mid);
double f_exact = f(x_mid);

double abs_error_lagrange = fabs(P_lagrange - f_exact);
double perc_error_lagrange = (abs_error_lagrange / f_exact) * 100;
double abs_error_newton = fabs(P_newton - f_exact);
double perc_error_newton = (abs_error_newton / f_exact) * 100;
 cout << fixed << setprecision(4) << x_mid << "\t";
cout << "exact value " << f_exact << "\t";
cout << "Lagrange = " << P_lagrange << "\t";
cout << "AE Lag = " << abs_error_lagrange << "\t";
cout << "PE lag = " << perc_error_lagrange << "%\t";
cout << "Newton = " << P_newton << "\t";
cout << "AE New = " << abs_error_newton << "\t";
 cout << "PE New = " << perc_error_newton << "%" << endl;
    }

    return 0;
}

