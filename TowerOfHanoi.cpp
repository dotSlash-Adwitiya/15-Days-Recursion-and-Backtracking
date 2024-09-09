#include<bits/stdc++.h>
using namespace std;

void hanoi(int n, int src, int dest, int aux, vector<vector<int>> &ans){
  if(n == 1){
    ans.push_back({src, dest});
    return;
  }

  // * Using the aux disk as destination and destination disk as aux
  hanoi(n-1, src, aux, dest, ans);
  ans.push_back({src,dest});
  // * Using the dest disk as destination and aux disk as source
  hanoi(n-1, aux, dest, src, ans);
}

vector<vector<int>> towerOfHanoi(int n) {
  vector<vector<int>> ans;
  hanoi(n, 1, 3, 2, ans);
  return ans;
}
