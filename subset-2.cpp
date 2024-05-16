#include<bits/stdc++.h>
using namespace std;

void helper(vector<vector<int>> &subsets, vector<int> &arr, int idx, vector<int> &ds) {        
  subsets.push_back(ds);
  
  for(int i = idx; i < arr.size(); i++) {
      if(i > idx && arr[i] == arr[i-1])
          continue;
      ds.push_back(arr[i]);
      helper(subsets, arr, i + 1, ds);
      ds.pop_back();
  }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
  vector<vector<int>> subsets;
  vector<int> ds;
  sort(nums.begin(), nums.end());
  helper(subsets, nums, 0, ds);
  return subsets;
}