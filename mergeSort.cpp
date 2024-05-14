#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high){
  int sz1 = mid - low + 1, sz2 = high - mid;
  int *v1 = new int [sz1];
  int *v2 = new int[sz2];

  int k = low;
  for(int i = 0; i < sz1; i++)
    v1[i] = arr[k++];

  for(int i = 0; i < sz2; i++)
    v2[i] = arr[k++];

  int i = 0, j = 0;
  k = low;
  while (i < sz1 && j < sz2)
  {
    if(v1[i] <= v2[j]){
      arr[k++] = v1[i];
      i++;
      // cout << "SVd";
    }
    else {
      arr[k++] = v2[j];
      j++;
    }
  }
  while (i < sz1)
  {
    arr[k++] = v1[i];
    i++;
  }

  while (j < sz2)
  {
    arr[k++] = v2[j];
    j++;
  }
}

void ms(vector<int> &arr, int low, int high){
  if(low >= high)
    return;
  int mid = low + (high - low)/2;
  ms(arr, low, mid);
  ms(arr, mid+1, high);
  merge(arr, low, mid, high);
}

vector<int> mergeSort(vector<int> &arr, int n){
  
  ms(arr, 0, n-1);
  return arr;
}

int main()
{
  vector<int> v = {4,1,3,9,7};

  mergeSort(v, v.size());

  for(auto it: v)
    cout << it << " ";
  
  cout << endl;

  return 0;
}