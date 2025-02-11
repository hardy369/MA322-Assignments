#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

vector<double> calculate_powers(double x, int degree) {
vector<double> powers(degree + 1);
powers[0] = 1;  // x^0 = 1
for (int i = 1; i <= degree; i++) {
 powers[i] = powers[i - 1] * x;
}
return powers;
}
// using gaussian elimination
vector<double> gaussianElimination(vector<vector<double>>& A, vector<double>& b) {
int n = A.size();
for (int i = 0; i < n; i++) {
 int maxRow = i;
 for (int k = i + 1; k < n; k++) {
if (fabs(A[k][i]) > fabs(A[maxRow][i])) {
maxRow = k;
}
}
swap(A[i], A[maxRow]);
swap(b[i], b[maxRow]);
for (int j = i + 1; j < n; j++) {
double factor = A[j][i] / A[i][i];
for (int k = i; k < n; k++) {
A[j][k] -= A[i][k] * factor;
}
b[j] -= b[i] * factor;
}}
vector<double> x(n);
for (int i = n - 1; i >= 0; i--) {
x[i] = b[i] / A[i][i];
for (int j = i - 1; j >= 0; j--) {
 b[j] -= A[j][i] * x[i];
}
}
return x;
}

int main() {
int num_points = 5;
int degree = num_points - 1;

vector<double> x_data = {1.0, 2.0, 3.0, 4.0, 5.0};
vector<double> y_data = {2.0, 8.0, 18.0, 32.0, 50.0};

 vector<vector<double>> A(num_points, vector<double>(degree + 1));
for (int i = 0; i < num_points; i++) {
 vector<double> powers = calculate_powers(x_data[i], degree);
for (int j = 0; j <= degree; j++) {
A[i][j] = powers[j];
}
}

vector<double> b(degree + 1, 0);
for (int i = 0; i < num_points; i++) {
for (int j = 0; j <= degree; j++) {
    b[j] += A[i][j] * y_data[i];
}
 }

vector<vector<double>> AT_A(degree + 1, vector<double>(degree + 1, 0));
for (int i = 0; i <= degree; i++) {
for (int j = 0; j <= degree; j++) {
 for (int k = 0; k < num_points; k++) {
AT_A[i][j] += A[k][i] * A[k][j];
 }
}
 }
vector<double> coefficients = gaussianElimination(AT_A, b);
   vector<double> x_test = {1.25, 1.70,3.5,4.25}; 
 for(int j=0;j< x_test.size();j++ ){
 double test_x =x_test [j];
    double y_test = 0;
    for (int i = 0; i <= degree; i++) {
        y_test += coefficients[i] * pow(test_x, i);
    }
    cout << "Polynomial evaluated at x = " << test_x << ": y = " << y_test << endl;
}


    return 0;
}

