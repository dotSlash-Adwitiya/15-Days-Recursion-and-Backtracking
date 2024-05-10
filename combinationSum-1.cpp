#include<bits/stdc++.h>
using namespace std;

/* 
 * Learning :  
 * How to choose a number unlimited number of times : Just make a RECURSIVE_CALL W/O moving forward in the indexes
 * Your confusion was : I couldn't think of a condition WHEN TO STOP The call, 
 * I though it would result in runtime error!
 */

// * T.C : O(2^T * K) - learn more on this
// * S.C : O(k * x) - learn more on this
void helper(vector<vector<int>> &comb, vector<int>& candidates, vector<int>& ds, int idx, int k) {
  if(idx == candidates.size()){
      if(k == 0)
          comb.push_back(ds);
      return;
  }
  
  if(candidates[idx] <= k) {
      ds.push_back(candidates[idx]);
      helper(comb, candidates, ds, idx, k - candidates[idx]);
      ds.pop_back();
  }

  helper(comb, candidates, ds, idx + 1, k);
  
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
  vector<vector<int>> combinations;
  vector<int> arr;

  helper(combinations, candidates, arr, 0, target);
  
  return combinations;
}