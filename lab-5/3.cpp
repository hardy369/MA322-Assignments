#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
double newton(double x, const vector<double>& x_values, const vector<double>& y_values) {
    int n = x_values.size();
    vector<double> coef = y_values;
    for (int j = 1; j < n; j++) {
        for (int i = n - 1; i >= j; i--) {
            coef[i] = (coef[i] - coef[i - 1]) / (x_values[i] - x_values[i - j]);
        }
    }
    double result = coef[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        result = result * (x - x_values[i]) + coef[i];
    }
    return result;
}
int main() {
    vector<double> x = {1.7, 1.74, 1.78, 1.82, 1.86};
    vector<double> sin_x = {0.9916, 0.9857, 0.9781, 0.9691, 0.9584};
    double x_new = 1.74;
    double sin_new = newton(x_new, x, sin_x);
    double cos_new = sin(M_PI / 2 - x_new);
    cout << "Interpolated sin(" << x_new << ") = " << sin_new << endl;
    cout << "cos(" << x_new << ") = " << cos_new << endl;
    return 0;
}
