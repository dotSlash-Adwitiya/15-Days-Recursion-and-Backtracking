#include<bits/stdc++.h>
using namespace std;

bool isPossible(bool graph[101][101], vector<int> &colored, int node, int color, int n){
  
  for(int i = 0; i < n; i++){ // Traversing on all the nodes
      // * i != node :  indicates that this isn't the same node as the one I am trying to color
      // * (because its not colored so no need to proceed if its the same node)
      // * graph[i][node] Checks, whether there's a node between the current Node(i) 
      // * and the one we're trying to color
      // * Then finally, check if the  
      if(i != node && graph[i][node] == 1 && colored[i] == color)
          return false;
  }
  return true;
}

bool graphColor(bool graph[101][101], vector<int> &colored, int node, int m, int n) {
  if(node == n)
      return true;
      
  for(int i = 1; i <= m; i++){ // * i = color
      if(isPossible(graph, colored, node, i, n)){ // * Check if its possible to color the current node with ith color
          colored[node] = i; // * Marking the Current Node with current color
          if(graphColor(graph, colored, node+1, m, n))
              return true;
          colored[node] = 0; // * Backtrack
      }
  }
  return false;
}


bool graphColoring(bool graph[101][101], int m, int n) {
  
  vector<int> colored(n, 0); // * vector of size n, to keep track if the nth node is COLORED or NOT already.

  return graphColor(graph, colored, 0, m, n);

}