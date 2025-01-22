
// 4. Given an array arr[] of n integers and a target value, the task is to 
//find the number of pairs of integers in the array whose sum is equal to target.

/*
 Author: Hoshang
 Created:
 */
#include <bits/stdc++.h>
using namespace std;

int countPairs(vector<int>& arr, int target) {
    unordered_map<int, int> freqMap; // To store frequency of elements
    int count = 0;

    for (int i = 0; i < arr.size(); i++) {
        int complement = target - arr[i]; // Find the complement for current element

        // Check if the complement exists in the map
        if (freqMap[complement] > 0) {
            count += freqMap[complement]; // Increment count by the frequency of complement
        }

        // Add the current element to the frequency map
        freqMap[arr[i]]++;
    }

    return count;
}

int main() {
   
	vector <int> arr = {2,3,12,32,54,5,4,22,78};

    
    int target = 54;

    // Calculate and output the number of pairs
    int result = countPairs(arr, target);
    cout << "The number of pairs with sum equal to " << target << " is: " << result << endl;

    return 0;
}
