/*
 Author: Hoshang
 Created:
 */
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;


// 6. Find the factorial of a large number


unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1; 
    }
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i; // Multiply all numbers from 2 to n
    }
    return result;
}

int main() {
    int num;
    cout << "Enter a number to calculate its factorial: ";
    cin >> num;

    if (num < 0) {
        cout << "Factorial of a negative number is not defined." << endl;
    } else {
        cout << "Factorial of " << num << " is " << factorial(num) << endl;
    }

    return 0;
}




