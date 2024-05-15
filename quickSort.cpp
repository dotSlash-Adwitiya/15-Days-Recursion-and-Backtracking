#include<bits/stdc++.h>
using namespace std;

int partition (int arr[], int low, int high)
{
  int pivot = arr[low];
  int i = low, j = high;
  
  do {
      // * 1st ptr will find a GREATER element than pivot
      while(i < high && arr[i] <= pivot) i++;

      // * 2nd ptr will find a SMALLER element than pivot
      while(j > low && arr[j] >= pivot) j--;
      
      if(i < j)
          swap(arr[i], arr[j]);
          
  }while(i < j);
  
  swap(arr[low], arr[j]);

  // * We need the new index of PIVOT, to DIVIDE the LIST
  return j;
}
//Function to sort an array using quick sort algorithm.
void quickSort(int arr[], int low, int high)
{
  if(low < high) {
      int pivotIdx = partition(arr, low, high);
      quickSort(arr, low, pivotIdx-1);
      quickSort(arr, pivotIdx+1, high);
  }
}