/*
 Author: Hoshang
 Created:
 */
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

// 3. Given an array of integers where each element represents the max number of steps
// that can be made forward from that element. The task is to find 
// the minimum number of jumps to reach the end of the array (starting from the first element).
// If an element is 0, then we cannot move through that element. If we can’t reach the end, return -1.


int minJumps(vector<int>& arr) {
    int n = arr.size();
    
    // If the array has only one element or is empty, no jumps are needed.
    if (n <= 1) return 0;

    // If the first element is 0, we cannot move forward, hence return -1.
    if (arr[0] == 0) return -1;

    int jumps = 1; // At least one jump is needed to start
    int maxReach = arr[0]; // Maximum index we can reach with the current number of jumps
    int steps = arr[0]; // Steps we can still take before we need to jump again

    for (int i = 1; i < n; i++) {
        
        if (i == n - 1) return jumps;	// If reached the last element, return the number of jumps

        // Update maxReach and steps
        maxReach = max(maxReach, i + arr[i]);
        steps--;

        // If no steps left, we need to jump
        if (steps == 0) {
            jumps++;
            // If we cannot move forward from the current position, return -1
            if (i >= maxReach) return -1;
            steps = maxReach - i;
        }
    }

    return -1; // In case it's not possible to reach the end
}

int main() {
    vector<int> arr = {6, 2, 4, 0, 5, 1, 1, 4, 2, 9};
    
    int result = minJumps(arr);
    if (result == -1)
        cout << "Can't reach the end" << endl;
    else
        cout << "Minimum number of jumps to reach the end: " << result << endl;

    return 0;
}

