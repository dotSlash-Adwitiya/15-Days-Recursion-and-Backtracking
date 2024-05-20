#include<bits/stdc++.h>
using namespace std;

void spacePermute(string &str, unordered_map<int,bool> &flag, string &ds, int l, int h, set<string> &ans) {

  if(ds.size() == h) {
    ans.insert(ds);
    return;
  }

  for(int i = 0; i < h; i++) {
    if(flag[i] == false) {  //* If its not visited yet
      flag[i] = true;  //* Mark it visited
      ds += str[i];
      spacePermute(str, flag, ds, l+1, h, ans);
      flag[i] = false;
      ds.pop_back();
    }
  }
}



vector<string>find_permutation(string S)
{
  int l = 0;
    int h = S.size();
    
    //* Declaring all auxilarry spaces
    vector<string> ans;
    set<string> st;
    
    //*By default unordered_map has false values assigned to bool part
    unordered_map<int, bool> flag;
        
    string out = "";

    spacePermute(S, flag, out, l, h, st);
    
    //* Copying set elements to vector
    for(auto it = st.begin(); it != st.end(); it++) 
        ans.push_back(*it);
    
    return ans;
}

// * 2nd Approach ( For integer based array )- O(1) SPACE :-
void helper(int idx, vector<int> &nums, vector<vector<int>> &ans){
  if(idx == nums.size()){
      ans.push_back(nums);
      return;
  }

  for(int i = idx; i < nums.size(); i++){
      swap(nums[i], nums[idx]);
      helper(idx+1, nums, ans);
      swap(nums[i], nums[idx]);
  }
}

vector<vector<int>> permute(vector<int>& nums) {
  vector<vector<int>> ans;
  helper(0,nums, ans);
  return ans;
}