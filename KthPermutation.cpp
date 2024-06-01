#include <bits/stdc++.h>

using namespace std;

// * BRUTE FORCE Solution
void permutationHelper(string & s, int index, vector < string > & res) {
  if (index == s.size()) {
    res.push_back(s);
    return;
  }
  for (int i = index; i < s.size(); i++) {
    swap(s[i], s[index]);
    permutationHelper(s, index + 1, res);
    swap(s[i], s[index]);
  }
}

string getPermutation(int n, int k) {
  string s;
  vector < string > res;
  //create string
  for (int i = 1; i <= n; i++) {
    s.push_back(i + '0');
  }
  permutationHelper(s, 0, res);
  //sort the generated permutations
  sort(res.begin(), res.end());
  //make k 0-based indexed to point to kth sequence
  auto it = res.begin() + (k - 1);
  return *it;
}

// * Optimised solution
string getPermutation(int n, int k) {
  int fact = 1;
  vector < int > numbers;
  for (int i = 1; i < n; i++) {
    fact = fact * i;
    numbers.push_back(i);
  }

  numbers.push_back(n);
  string ans = "";
  k = k - 1;
  while (true) {
    // * Finding the initial Range, Ex : {This_position,_,_,_}, then
    // * Finding the initial Range, Ex : {_,This_position,_,_}, then
    // * Finding the initial Range, Ex : {_,_This_position,_}, then so on......
    ans = ans + to_string(numbers[k / fact]); 
  
    numbers.erase(numbers.begin() + k / fact);

    // * If no elements left then break out of here
    if (numbers.size() == 0) {
      break;
    }

    k = k % fact; // * K's range will be reduced from 16 (for 17) to -> 16%6 = 2 
    fact = fact / numbers.size();
  }
  return ans;
}