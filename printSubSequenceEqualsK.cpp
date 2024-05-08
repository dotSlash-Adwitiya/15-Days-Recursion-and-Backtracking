#include<bits/stdc++.h>
using namespace std;

void helper(vector<vector<int>> &ans, vector<int> &temp, vector<int> arr, int idx, int sum, int k) {
  if(idx >= arr.size()) {
    if(sum == k){
      ans.push_back(temp);
    }
    return;
  }

  sum += arr[idx];
  temp.push_back(arr[idx]);

  helper(ans, temp, arr, idx+1, sum, k);
  temp.pop_back();
  sum -= arr[idx];
  helper(ans, temp, arr, idx+1, sum, k);

}

vector<vector<int>> printSubSequence(vector<int> arr, int k) {
  vector<int> temp;
  vector<vector<int>> ans;
  int sum = 0;

  helper(ans, temp, arr, 0, sum, k);

  return ans;

}

int main()
{
  vector<vector<int>> ans = printSubSequence({1, 2, 2, 4, 1, 5, 3}, 5);

  for(vector<int> v : ans){
    for(int it : v)
      cout << it << " ";
    cout << endl;

  }

  return 0;
}