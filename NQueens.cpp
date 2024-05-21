#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<string> &board, int row, int col, int n) {
    int trow = row, tcol = col;

    // * Check LeftUpperDiagonals
    while(trow >= 0 && tcol >= 0){
        if(board[trow][tcol] == 'Q')
            return false;
        trow--;
        tcol--;
    }

    // * Check Current Row's Left Side
    trow = row, tcol = col;
    while(tcol >= 0){
        if(board[trow][tcol] == 'Q')
            return false;
        tcol--;
    }

    // * Check lower Left Diagonals
    trow = row, tcol = col;
    while(trow < n && tcol >= 0){
        if(board[trow][tcol] == 'Q')
            return false;
        trow++;
        tcol--;
    }

    return true;
}

void solve(vector<vector<string>> &ans, vector<string> &board, int col, int n) {
    if(col == n) {
        ans.push_back(board);
        return;
    }

    for(int row = 0; row < n; row++) {
            board[row][col] = 'Q';
        if(isSafe(board, row, col, n)){   // * Check if its safe to place the Queen on current position
                                          // * else move to next row downwards (↓)
            solve(ans, board, col + 1, n); // * MOVE TO NEXT COLUMN forward (->)
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> findPossiblePlacementsOfQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n , '.');


    /* 
    * For n = 4
    * [0[0,1,2,3], 
    * 1[0,1,2,3], 
    * 2[0,1,2,3], 
    * 3[0,1,2,3]]
    */

    // * Below line creates something like above, that's why we're able to access it using 2D Indices.
    for(int i = 0; i < n; i++)
    board[i] = s;

    for(int i = 0; i < board.size(); i++)
      cout << board[i].size() << " ";
    
    cout << endl;

    solve(ans, board, 0, n);

    return ans;
}

int main()
{
  vector<vector<string>> NQueens = findPossiblePlacementsOfQueens(8);

  for(vector<string> &v : NQueens){
    for(string s: v){
        cout << s << endl;
    }
    cout << endl;
  }
  return 0;
}