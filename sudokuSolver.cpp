#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<char>> &board, int row, int col, char ch) {

  for(int i = 0; i < 9; i++) {

  // * Check for currRow
  if(board[row][i] == ch)
      return false;
  // * Check for currCol
  if(board[i][col] == ch)
      return false;
  
  // * Check for 3*3 Sub-Box
  if(board[3 * (row/3) + (i/3)][3 * (col/3) + (i % 3)] == ch)
      return false;
  }   
  return true;
}

bool solve(vector<vector<char>> &board){
  for(int i = 0; i < board.size(); i++) {
      for(int j = 0; j < board[0].size(); j++ ) {
          if(board[i][j] == '.'){
              for(char c = '1'; c <= '9'; c++) {
                  if(isValid(board, i, j, c)){
                      board[i][j] = c;
                      
                      bool solutionFound = solve(board);
                      if(solutionFound) // * If one solution is found, don't need to proceed further.
                          return true;
                      
                      else // *Else backtrack and empty the filled position again
                          board[i][j] = '.';
                  }
              }
              return false;
          }
      }
  }
  return true;
}

void solveSudoku(vector<vector<char>>& board) {
  solve(board);
}

int main ()
{

  return 0;
}