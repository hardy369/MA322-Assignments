#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>  

using namespace std;

int main() {
 long double fd=0;
 long double bd=0;
    long double x[5] = {2.718281828, -3.141592654, 1.414213562, 0.5772156649, 0.3010299957};
    long double y[5] = {1486.2499, 878366.9879, -22.37492, 4773714.647, 0.000185049};
    for(int i=0;i<5;i++){
fd=fd+x[i]*y[i];
bd=bd+x[4-i]*y[4-i];
}
 cout  << "forward order"<<setprecision(50)<<fd*10000000000 << endl;
cout  << "backward order"<<setprecision(50)<<bd*10000000000<< endl;
    vector<long double> positiveNumbers;
    vector<long double> negativeNumbers;
    for (int i = 0; i < 5; i++) {
        if (x[i] >= 0) positiveNumbers.push_back(x[i]);
        else negativeNumbers.push_back(x[i]);
        if (y[i] >= 0) positiveNumbers.push_back(y[i]);
        else negativeNumbers.push_back(y[i]);
    }
    sort(positiveNumbers.begin(), positiveNumbers.end(), greater<long double>());
    sort(negativeNumbers.begin(), negativeNumbers.end());
    long double sumPositive = 0;
    for (long double num : positiveNumbers) {
        sumPositive += num;}
   
    long double sumNegative = 0;
    for (long double num : negativeNumbers) {
        sumNegative += num; }
    long double finalResult = sumPositive + sumNegative;
    cout << "Sum of positive numbers : " << setprecision(50) <<sumPositive << endl;
    cout << "Sum of negative numbers : " << setprecision(50) <<sumNegative << endl;
    cout << "Final result : " <<setprecision(50) << finalResult << endl;

    return 0;
}

