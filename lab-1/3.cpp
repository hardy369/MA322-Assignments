#include <iostream>
#include <cmath>
#include <iomanip>  
using namespace std;

long double f(long double x) {
return sqrt(x*x +1) - 1;
}


long double g(long double x) {
    return x*x / (sqrt(x*x + 1) + 1);
}

int main() {
    long double A[30];
    long double B[30];
    
for (int i=0; i<30; i++) {
long double x = pow(8, -i);  
 A[i] = f(x);  
 B[i] = g(x);  
        
cout << "A[" << i << "] = " << setprecision(50)<<A[i] << endl;
cout << "B[" << i << "] = " << setprecision(50)<<B[i] << endl;
cout<< "difference is:"<<setprecision(50)<<B[i]-A[i]<<endl;
    }

    return 0;
}
//it is giving almost same computation till 10 iterations after 10 f is tending to 0 where as g is not.
