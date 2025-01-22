 // Given the heights of n towers and a positive integer k, 
// increase or decrease the height of all towers by k (only once). After modifications, 
 // the task is to find the minimum difference between the heights of the tallest and the shortest tower.

 /*
 Author: Hoshang
 Created:
 */
#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum difference after modifying heights
int minimizeHeightDifference(vector<int>& heights, int k) {
    int n = heights.size();

    // If only one tower, the difference is always 0
    if (n == 1) return 0;

    // Sort the array to analyze the height differences
    sort(heights.begin(), heights.end());

    // The initial difference (before modification)
    int diff = heights[n - 1] - heights[0];

    // Variables to track the smallest and largest tower after modification
    int smallest, largest;

    for (int i = 1; i < n; i++) {
        if (heights[i] >= k) {
            // Decreasing the height of ghe first tower and increase the height of the last tower
            smallest = min(heights[0] + k, heights[i] - k);
            largest = max(heights[i - 1] + k, heights[n - 1] - k);
            diff = min(diff, largest - smallest);
        }
    }

    return diff;
}

int main() {

    int n = 6;		// number of towers

    vector<int> heights = {10,4,5,8,11,13};
    
    int k = 3;

    // Calculate and output the minimum height difference
    int result = minimizeHeightDifference(heights, k);
    cout << "The minimum difference between the tallest and shortest tower is: " << result << endl;

    return 0;
}
