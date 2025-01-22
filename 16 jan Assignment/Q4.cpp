/*
 Author: Hoshang
 Created:
 */

// 5 . Given an integer array arr[] of size n, find the inversion count in the array. 
// Two array elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;


// Function to merge two halves and count inversions
int mergeAndCount(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    int invCount = 0;
    int i = left;    // Starting index for left subarray
    int j = mid + 1; // Starting index for right subarray
    int k = left;    // Starting index to be sorted
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount += (mid - i + 1); // Count inversions
        }
    }
    
    // Copy the remaining elements of left subarray
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    
    // Copy the remaining elements of right subarray
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    
    // Copy the sorted subarray into original array
    for (int i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
    
    return invCount;
}

// Function to sort the array and count inversions
int mergeSortAndCount(vector<int>& arr, vector<int>& temp, int left, int right) {
    int invCount = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        invCount += mergeSortAndCount(arr, temp, left, mid);
        invCount += mergeSortAndCount(arr, temp, mid + 1, right);
        
        invCount += mergeAndCount(arr, temp, left, mid, right);
    }
    return invCount;
}

int main() {
    vector<int> arr = {1, 20, 6, 4, 5};  // Example input
    vector<int> temp(arr.size());  // Temporary array for merge sort
    int result = mergeSortAndCount(arr, temp, 0, arr.size() - 1);
    cout << "Number of inversions: " << result << endl;
    return 0;
}
