#include <iostream>
using namespace std;

int s = 0;

void m(int arr[], int l, int r, int q){
  int right[r-q];
  int left[q-l+1];
  for(int i = 0; i < q-l+1; i++){
    left[i] = arr[l+i];
  }
  for(int i = 0; i < r-q; i++){
    right[i] = arr[i+q+1];
  }
  int x = 0;
  int y = 0;
  int a = l;

  while(x<q-l+1 && y<r-q){
    if(left[x] < right[y]){
      arr[a] = left[x];
      a++;
      x++;
    }else{
      arr[a] = right[y];
      s+= q+y-a+1;
      y++;
      a++;
    }
  }
  while(x<q-l+1){
    arr[a] = left[x];
    a++;
    x++;
  }
  while(y<r-q){
    arr[a] = right[y];
    a++;
    y++;
  }
}


void f(int arr[], int l, int r){
  if(r>l){
    int q = (r+l) / 2;
    f(arr, l, q);
    f(arr, q+1, r);
    m(arr, l, r, q);    
  }
}


int main() {
  int n;
  cin >> n;
  int arr[n];
  for(int i =0; i < n; i++){
    cin >> arr[i];
  }
  f(arr, 0, n-1);
  cout << s;
}
// inversion of permutation
// mede with merge sort