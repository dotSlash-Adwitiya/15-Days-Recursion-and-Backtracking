#include<bits/stdc++.h>
using namespace std;

void hanoi(int n, int src, int dest, int aux, vector<vector<int>> &ans){
  if(n == 1){
      ans.push_back({src, dest});
      return;
  }

  hanoi(n-1, src, aux, dest, ans);
  ans.push_back({src,dest});
  hanoi(n-1, aux, dest, src, ans);
}

vector<vector<int>> towerOfHanoi(int n) {
  vector<vector<int>> ans;
  hanoi(n, 1, 3, 2, ans);
  return ans;
}
