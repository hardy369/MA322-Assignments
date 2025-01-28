#include <iostream>
#include <vector>
#include <cmath>
 
using namespace std;
float hermite(float x, const vector<float>& xi, const vector<float>& fi, const std::vector<float>& fpi) {
int n = xi.size();
vector<float> z(2 * n);
vector<float> Q(2 * n * 2 * n, 0);
 
for (int i = 0; i < n; ++i) {
z[2 * i] = z[2 * i + 1] = xi[i];
Q[2 * i * 2 * n] = Q[(2 * i + 1) * 2 * n] = fi[i];
Q[(2 * i + 1) * 2 * n + 1] = fpi[i];
if (i > 0) {
Q[2 * i * 2 * n + 1] = (Q[2 * i * 2 * n] - Q[(2 * i - 1) * 2 * n]) / (z[2 * i] - z[2 * i - 1]);
}
}
for (int i = 2; i < 2 * n; ++i) {
for (int j = 2; j <= i; ++j) {
Q[i * 2 * n + j] = (Q[i * 2 * n + j - 1] - Q[(i - 1) * 2 * n + j - 1]) / (z[i] - z[i - j]);
}
}
float result = Q[0];
float product = 1.0;
for (int i = 1; i < 2 * n; ++i) {
product *= (x - z[i - 1]);
result += Q[i * 2 * n + i] * product;
}
return result;}
void print(){
cout<<" 2*x^4 - x^2 + x +1 "<<endl;
}
int main() {
vector<float> xi = {-1, 0, 1};
vector<float> fi = {1, 1, 3};
vector<float> fpi = {-5, 1, 7};
 
float x1 = -0.5, x2 = 0.5;
 
float estimate_f1 = hermite(x1, xi, fi, fpi);
float estimate_f2 = hermite(x2, xi, fi, fpi);
 
 
float exact_f1 = 33.0 / 64.0;
float exact_f2 = 97.0 / 64.0;
 
float error_f1 = abs((estimate_f1 - exact_f1) / exact_f1) * 100;
float error_f2 = abs((estimate_f2 - exact_f2) / exact_f2) * 100;
 
cout << "Estimated f(-0.5): " << estimate_f1 << endl;
cout << "Estimated f(0.5): " << estimate_f2 << endl;
cout << "Percentage error at f(-0.5): " << error_f1 << "%\n";
cout << "Percentage error at f(0.5): " << error_f2 << "%\n";
print();
 
return 0;
}
