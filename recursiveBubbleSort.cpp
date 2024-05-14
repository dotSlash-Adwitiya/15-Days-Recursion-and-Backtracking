#include<bits/stdc++.h>
using namespace std;

void recSort(int arr[], int n, int i) {
  
  if(i == n)
      return;
  
  for(int j = 0; j < n-i-1; j++)
      if(arr[j] > arr[j+1])
          swap(arr[j], arr[j+1]);
          
  recSort(arr, n, i+1);
}

// * Recursive method
void recursiveBubbleSort(int arr[], int n) {
  recSort(arr, n, 0);
}

// * Iterative method
void bubbleSort(int arr[], int n){
  for(int i = 0; i < n-1; i++) {
    for(int j = 0; j < n-i-1; j++){
      if(arr[j] > arr[j+1])
        swap(arr[j], arr[j+1]);
    }
  }
}