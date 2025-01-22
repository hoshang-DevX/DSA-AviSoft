/*
 Author: Hoshang
 Created:
 */
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

// 1. Given an array arr[] consisting of only 0s, 1s, and 2s.
 // The task is to sort the array, i.e., put all 0s first, then all 1s and all 2s in last.

void SortArray(vector <int>& nums ){
	int left = 0, mid = 0, right = nums.size()-1;
	while ( mid <= right){
		if (nums[mid] == 0){		// 0 needs to go to the left pos 
			swap(nums[left] , nums[mid]);
			left++;
			mid++;
		}

		else if( nums[mid] == 1)	//	at the right place
			mid++;

		else if( nums[mid] == 2){	// 2 needs to go to the right pos
			swap ( nums[mid], nums[right]);
			right--;
		}
	}
}

int main(){


    vector <int> arr = {1,2,0,1,0,2,2,1,0};
    int n = arr.size()-1;

    SortArray(arr);

    for( int i = 0; i < n; i ++){
    	cout << arr[i] << " ";
    }

    return 0;
}