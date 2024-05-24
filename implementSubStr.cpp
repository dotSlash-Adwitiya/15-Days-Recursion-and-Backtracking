#include<bits/stdc++.h>
using namespace std;


// * Implementing because had doubts in the str.substr() inbuilt function.
string subStr(string str, int startIdx, int length) {
  if(startIdx > str.size())
    return "-1";

  string subString = "";
  for(int i = 0; i < length; i++)
    subString += str[startIdx++];

  return subString;
}

int main(){
  
  cout << subStr("aabb", 0, 2);
  return 0;
}