#include<bits/stdc++.h>
using namespace std;

// * Possible solution, in order to avoid same combination again, we use hash set.
void helper(set<vector<int>> &comb, vector<int>& candidates, vector<int>& ds, int idx, int k) {
  if(idx == candidates.size()){
      if(k == 0)
          comb.insert(ds);
      return;
  }
  
  if(candidates[idx] <= k){
      ds.push_back(candidates[idx]);
      helper(comb, candidates, ds, idx + 1, k - candidates[idx]);
      ds.pop_back();
  }

  helper(comb, candidates, ds, idx + 1, k);
}

vector<vector<int>> CombinationSum2(vector<int> A,int n, int k)
{
    set<vector<int>> temp;
    vector<vector<int>> combinations;
    vector<int> arr;
    sort(A.begin(), A.end());
    
    helper(temp, A, arr, 0, k);

    // * Convert SET of VECTORS to Vector of Vector;
    for(vector<int> vec : temp) {
        vector<int> v;
        for(int ele : vec)
            v.push_back(ele);
        combinations.push_back(v);
    }

    return combinations;
}

// * T.C : O(2^N * K) 
// * S.C : O(K * x) {x = valid combinations}

// * Recursive utilization
// * New Pattern : Picking up all the subsequences rather than elements.
// * Loop inside the recursive function.
void helper(vector<vector<int>> &comb, vector<int>& arr, vector<int>& ds, int idx, int k) {

    if(k == 0){
    comb.push_back(ds);
    return;
    }


    for(int i = idx; i < arr.size(); i++) {
    // * First base case, check
    if(i > idx && arr[i] == arr[i-1])
        continue;
    if(arr[i] > k)
        break;
    ds.push_back(arr[i]);
    helper(comb, arr, ds, i+1, k-arr[i]);
    ds.pop_back();
    }
}


vector<vector<int>> combinationSum2(vector<int>& A, int k) {
    vector<int> v;
    vector<vector<int>> combinations;
    sort(A.begin(), A.end());
    
    helper(combinations, A, v, 0, k);

    return combinations;
}