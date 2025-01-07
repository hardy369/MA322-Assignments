#include <iostream>
#include <cmath>
#include <iomanip>  

using namespace std;

long long fact(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
float e = 2.71828182846;
long double x = 2.0; //change x here
long double sinx = 0.0;
float val=6.71884969739; //uncomment this for x=2 
//float val=0.24265526859; //uncomment this for x=0.2
int n = 15; //change the number of terms here  
    for (int i = 0; i < n; i++) {      
        long double term = pow(-1, i) * pow(x, 2 * i + 1) / fact(2 * i + 1);   
        sinx += term; }
 long double exp =pow(e,x)*sinx;
    cout << setprecision(50) << exp << endl;
    long double aerror =abs(exp-val);
    long double rerror =  abs(aerror / val);
    cout<<"absolute error:"<< aerror<< endl;
      cout<<"relative error:"<<rerror << endl;
    return 0;
}

