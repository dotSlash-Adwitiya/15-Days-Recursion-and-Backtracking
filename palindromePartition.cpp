#include<bits/stdc++.h>
using namespace std;


/*
  * Catch is : Figure out, how to include the substring in the temporary vector of answer.
  * Figure out, when there will exist a loop inside a recursive fn.
  * 
*/ 

bool isPalindrome(string &str, int start, int end) {
  
  while(start < end){
      if(str[start++] != str[end--])
          return false;
  }
  return true;
}

void partitionString(vector<vector<string>> &ans, vector<string> &temp, string &s, int idx){
  if(idx == s.size()){
      ans.push_back(temp);
      return;
  }

  for(int i = idx; i < s.size(); i++){
      // * If its a palindrome, only then include it and make a call,
      // * NOTE : a single character is a PALINDROME
      if(isPalindrome(s, idx, i)){
        // * Substr function implemented, to clear my own doubts
          temp.push_back(s.substr(idx, i-idx+1));
          partitionString(ans, temp, s, i + 1);
          temp.pop_back();
      }
  }
}