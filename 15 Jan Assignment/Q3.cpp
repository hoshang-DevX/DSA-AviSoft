// 3. Given two sorted arrays,
// the task is to merge them in a sorted manner.


/*
 Author: Hoshang
 Created:
 */
#include <bits/stdc++.h>
using namespace std;

// Function to merge two sorted arrays
vector<int> mergeSortedArrays(vector<int>& arr1, vector<int>& arr2) {
    int n1 = arr1.size();
    int n2 = arr2.size();
    vector<int> result;

    int i = 0, j = 0;

    // Traverse both arrays and pick the smaller element
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            result.push_back(arr1[i]);
            i++;
        } else {
            result.push_back(arr2[j]);
            j++;
        }
    }

    // If there are remaining elements in arr1
    while (i < n1) {
        result.push_back(arr1[i]);
        i++;
    }

    // If there are remaining elements in arr2
    while (j < n2) {
        result.push_back(arr2[j]);
        j++;
    }

    return result;
}

int main() {
    // Input: Two sorted arrays
    vector <int> arr1 = {2,3,6,8,9};
    vector <int> arr2 = {12,15,18,21,45};

    // Merge the arrays
    vector<int> mergedArray = mergeSortedArrays(arr1, arr2);

    // Output the merged sorted array
    cout << "The merged sorted array is: ";
    for (int i = 0; i < mergedArray.size(); i++) {
        cout << mergedArray[i] << " ";
    }
    cout << endl;

    return 0;
}
