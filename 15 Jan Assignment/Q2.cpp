// Given an array arr[], the task is to find the subarray that has the maximum sum 
// and return its sum.

/*
 Author: Hoshang
 Created:
 */
#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum sum of a subarray
int maxSubArraySum(vector<int>& arr) {
    int maxSum = INT_MIN;  // Store the maximum sum
    int currentSum = 0;    // Store the current sum

    for (int i = 0; i < arr.size(); i++) {
        currentSum += arr[i];             // Add current element to the current sum
        maxSum = max(maxSum, currentSum); // Update the maximum sum

        // If current sum becomes negative, reset it to 0
        if (currentSum < 0) {
            currentSum = 0;
        }
    }
    return maxSum;
}

int main() {

    vector <int> arr ={0,1,3,2,-1,-4};

    // Calculate and output the maximum sum
    int result = maxSubArraySum(arr);
    cout << "The maximum subarray sum is: " << result << endl;

    return 0;
}