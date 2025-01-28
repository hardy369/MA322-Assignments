#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    long double x[5] = {2.718281828, -3.141592654, 1.414213562, 0.5772156649, 0.3010299957};
    long double y[5] = {1486.2499, 878366.9879, -22.37492, 4773714.647, 0.000185049};

    vector<long double> positiveNumbers;
    vector<long double> negativeNumbers;

    for (int i = 0; i < 5; i++) {
        if (x[i] >= 0) positiveNumbers.push_back(x[i]);
        else negativeNumbers.push_back(x[i]);

        if (y[i] >= 0) positiveNumbers.push_back(y[i]);
        else negativeNumbers.push_back(y[i]);
    }

    sort(positiveNumbers.begin(), positiveNumbers.end());

    sort(negativeNumbers.begin(), negativeNumbers.end());

    long double sumPositive = 0;
    for (long double num : positiveNumbers) {
        sumPositive += num;
    }

    long double sumNegative = 0;
    for (long double num : negativeNumbers) {
        sumNegative += num;
    }

    long double finalResult = sumPositive + sumNegative;

    cout << "Sum of positive numbers (sorted smallest to largest): " << sumPositive << endl;
    cout << "Sum of negative numbers (sorted smallest to largest): " << sumNegative << endl;
    cout << "Final result (positive sum + negative sum): " << finalResult << endl;

    return 0;
}

