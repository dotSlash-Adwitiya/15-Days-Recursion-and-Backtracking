#include<bits/stdc++.h>
using namespace std;

int cntSubSequences(vector<int> arr, int idx, int &sum, int k) {
  if(idx >= arr.size()) {
    if(sum == k)
      return 1;
    return 0;
  }


  sum += arr[idx];
  int take = cntSubSequences(arr, idx+1, sum, k);

  sum -= arr[idx];
  int notTake = cntSubSequences(arr, idx+1, sum, k);
  return take + notTake;
}

int cntSubSequenceSum(vector<int> arr, int k) {
  int sum = 0;
  return cntSubSequences(arr, 0, sum, k);
}

int main()
{
  cout << "Total no of Subsequences are : " << cntSubSequenceSum({1, 2, 2, 4, 1, 5, 3}, 5) << endl;

  return 0;
}

