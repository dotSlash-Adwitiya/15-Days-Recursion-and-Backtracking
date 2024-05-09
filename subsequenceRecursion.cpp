#include<bits/stdc++.h>
using namespace std;

// * PATTERN Learnt : Take and NOT Take pattern.
// * T.C : O(2^n)
// * S.C : O(N), because depth of recursion will be (at max) = size of given arr[]
void helper(int arr[], vector<int> &v, int idx, int n) {
  if(idx >= n){
    for(auto it : v)
      cout << it << " ";
    if(v.size() == 0) cout << "{}";
    cout << endl;
    return;
  }

  // * Taking the Ele Call
  v.push_back(arr[idx]);
  helper(arr, v, idx+1, n);
  v.pop_back();

  // * NOT Take call
  helper(arr, v, idx+1, n);
}

void printSubsequence(int arr[], int n) {
  vector<int> v;
  helper(arr, v, 0, n);
}

int main()
{
  int arr[] = {3,1,2};

  printSubsequence(arr, sizeof(arr)/sizeof(arr[0]));
  return 0;
}