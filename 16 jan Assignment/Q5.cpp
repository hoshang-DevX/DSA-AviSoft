/*
 Author: Hoshang
 Created:
 */

// 6. Given three sorted arrays in non-decreasing order, print all common elements in these arrays.

#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

void findCommonElements(const vector<int>& arr1, const vector<int>& arr2, const vector<int>& arr3) {
    int i = 0, j = 0, k = 0; // Initialize pointers for the three arrays

    cout << "Common elements are: ";
    while (i < arr1.size() && j < arr2.size() && k < arr3.size()) {
        // If all three elements are equal, print it and move all pointers
        if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
            cout << arr1[i] << " ";
            i++;
            j++;
            k++;
        }
        // Find the smallest element and move that pointer
        else if (arr1[i] < arr2[j]) {
            i++;
        }
        else if (arr2[j] < arr3[k]) {
            j++;
        }
        else {
            k++;
        }
    }
    cout << endl;
}

int main() {
    vector<int> arr1 = {1, 5, 10, 20, 40, 80};
    vector<int> arr2 = {6, 7, 20, 80, 100};
    vector<int> arr3 = {3, 4, 15, 20, 30, 70, 80, 120};

    findCommonElements(arr1, arr2, arr3);

    return 0;
}



