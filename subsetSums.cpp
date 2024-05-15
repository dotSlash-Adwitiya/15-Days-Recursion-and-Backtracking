#include<bits/stdc++.h>
using namespace std;

// * T.C : O(2^N)
// * S.C : O(2^N)
void helper(vector<int> arr, vector<int> &ans, int sum, int idx, int n) {
  if(idx >= n){
      ans.push_back(sum);
      return;
  }
  
  // * Pick call
  helper(arr, ans, sum += arr[idx], idx + 1, n);

  // * NOT Pick call
  helper(arr, ans, sum -= arr[idx], idx + 1, n);
}

vector<int> subsetSums(vector<int> arr, int n) {
  vector<int> ans;
  int sum = 0, idx = 0;
  
  helper(arr, ans, sum, idx, n);
  return ans;
}