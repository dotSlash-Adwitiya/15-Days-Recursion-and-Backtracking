#include<bits/stdc++.h>
using namespace std;


//* Optimised approach using hashing :-
void solveOptimised(vector<vector<string>> &ans, vector<string> &board, vector<int> &upperDiagonal,
      vector<int> &leftRow, vector<int> &lowerDiagonal, int col, int n){

      if(col == n){
        ans.push_back(board);
        return;
      }        

      for(int row = 0; row < n; row++) {
          if(!upperDiagonal[row+col] && !leftRow[row] && !lowerDiagonal[n-1 + col-row]){
            board[row][col] = 'Q';
            upperDiagonal[row + col] = 1;
            leftRow[row] = 1;
            lowerDiagonal[n-1+col-row] = 1;
            solveOptimised(ans, board, upperDiagonal, leftRow, lowerDiagonal, col + 1, n);
            board[row][col] = '.';
            upperDiagonal[row + col] = 0;
            leftRow[row] = 0;
            lowerDiagonal[n-1+col-row] = 0;
          }
      }    
}
vector<vector<string>> OptimisedNQueens(int n) {
      vector<vector<string>> ans;
      vector<string> board(n);
      string s(n , '.');
      
      for(int i = 0; i < n; i++)
      board[i] = s;

      vector<int> upperDiagonal(2*n-1, 0), leftRow(n, 0), lowerDiagonal(2*n-1, 0);
      solveOptimised(ans, board, upperDiagonal, leftRow, lowerDiagonal, 0, n);
      return ans;
}

//*! Below is O(N!) Approach :-
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
  vector<vector<string>> NQueens = OptimisedNQueens(4);

  for(vector<string> &v : NQueens){
    for(string s: v){
        cout << s << endl;
    }
    cout << endl;
  }
  return 0;
}