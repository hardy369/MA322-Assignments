#include <iostream>
#include <cmath>
#include <cstdlib>
double g(double x) { return sqrt(exp(-x) * cos(x)); }
void fixedPointIteration(double x0, double tolerance = 1e-6, int maxIterations = 1000) {
    double xOld = x0, xNew; int iterations = 0;
    while (iterations < maxIterations) {
        xNew = g(xOld);
        if (fabs(xNew - xOld) < tolerance) {
            std::cout << "The approximate root is: " << xNew << std::endl;
            std::cout << "Number of iterations : " << iterations + 1 << std::endl;
            return;
        }
        xOld = xNew; iterations++;
    }
    std::cout << " the maximum number of iterations reached but no convergence." << std::endl;
}
int main() {
    double x0;
    std::cout << "Enter the initial guess (x0): ";
    std::cin >> x0;
    fixedPointIteration(x0);
    return 0;
}

