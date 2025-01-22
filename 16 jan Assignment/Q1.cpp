/*
 Author: Hoshang
 Created:
*/
			// LEETCODE problem: 42.

// 1. Trapping Rainwater Problem states that given an array of n non-negative integers arr[] 
// representing an elevation map where the width of each bar is 1,
// compute how much water it can trap after rain.

#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;


int trap(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int leftMax = height[left];
        int rightMax = height[right];
        int water = 0;

        while ( left < right)
        {
            if(leftMax < rightMax){
                left++;
                leftMax = max(leftMax, height[left]);
                water += leftMax - height[left];
            }
            else {
                right--;
                rightMax = max(rightMax, height[right]);
                water += rightMax - height[right];
            }
        }
        return water;
}

int main(){

	vector <int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

	int ans = trap(height);
	cout << ans;
	return 0;


}