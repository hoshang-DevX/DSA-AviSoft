/*
 Author: Hoshang
 Created:
 */
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;


// 2. Given an array arr[] of size n and an integer sum,
// the task is to check if there is a triplet in the array
// which sums up to the given target sum.

vector<vector<int>> threeSum(vector<int>& nums,int target) {
        vector<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            // to check if adjacent element is same.. for i
            if (i != 0 && nums[i] == nums[i - 1])
                continue;

            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum > target) {
                    k--;
                }
                if (sum < target) {
                    j++;
                }
                if (sum == target) {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    // skipping the duplicates - for j & k
                    while(j<k && nums[j]== nums[j-1]) j++;
                    while(j<k && nums[k] == nums[k+1]) k--;
                }
            }
        }
        return ans;
    }

int main(){

	vector<int> arr = {-1,0,1,2,-1,-4};
	int target = 0;

	vector< vector<int> > result = threeSum(arr,target);

	// Printing the result
    cout << "Triplets that sum to " << target << " are: " << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j < result[i].size() - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }
	return 0;

}