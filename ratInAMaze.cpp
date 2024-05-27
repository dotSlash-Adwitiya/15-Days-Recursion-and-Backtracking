#include<bits/stdc++.h>
using namespace std;

bool moveDown(vector<vector<int>> &m, vector<vector<int>> &visited, int i, int j, int n) {
  if(i >= n || (visited[i][j] == 1) || m[i][j] == 0) 
      return false;
  
  return true;
}

bool moveLeft(vector<vector<int>> &m, vector<vector<int>> &visited, int i, int j, int n) {
  if(j < 0 || (visited[i][j] == 1) || m[i][j] == 0) 
      return false;
  return true;
}

bool moveRight(vector<vector<int>> &m, vector<vector<int>> &visited, int i, int j, int n) {
  if(j >= n || (visited[i][j] == 1) || m[i][j] == 0) 
      return false;
  return true;
}

bool moveUp(vector<vector<int>> &m, vector<vector<int>> &visited, int i, int j, int n) {
  if(i < 0 || (visited[i][j] == 1) || m[i][j] == 0) 
      return false;
  return true;
}

void helper(vector<vector<int>> &maze, vector<vector<int>> &visited, vector<string> &path, string &possiblePath, int i, int j, int n) {
  if(i == n-1 && j == n-1){
      path.push_back(possiblePath);
      return;
  }
  
  if(moveDown(maze, visited, i+1, j, n)){
      visited[i][j] = 1;
      possiblePath += "D";
      helper(maze, visited, path, possiblePath, i+1, j, n);
      visited[i][j] = 0;
      possiblePath.pop_back();
  }
  if(moveLeft(maze, visited, i, j-1, n)){
      visited[i][j] = 1;
      possiblePath += "L";
      helper(maze, visited, path, possiblePath, i, j-1, n);
      visited[i][j] = 0;
      possiblePath.pop_back();
  }
  if(moveRight(maze, visited, i, j+1, n)){
      visited[i][j] = 1;
      possiblePath += "R";
      helper(maze, visited, path, possiblePath, i, j+1, n);
      visited[i][j] = 0;
      possiblePath.pop_back();
  }
  if(moveUp(maze, visited, i-1, j, n)){
      visited[i][j] = 1;
      possiblePath += "U";
      helper(maze, visited, path, possiblePath, i-1, j, n);
      visited[i][j] = 0;
      possiblePath.pop_back();
  }
  
  
}

vector<string> findPath(vector<vector<int>> &m, int n) {
  vector<string> paths;
  string possiblePath = "";
  vector<vector<int>> visited(n, vector<int>(n, 0));
  
  if(m[0][0] == 1) 
      helper(m, visited, paths, possiblePath, 0, 0, n);

  
  return paths;
}