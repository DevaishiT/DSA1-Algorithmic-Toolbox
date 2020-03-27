#include <bits/stdc++.h>

using namespace std;

long long merge(int a[], int left, int mid, int right) 
{ 
    int i, j, k; 
    int n1 = mid - left + 1; 
    int n2 =  right - mid; 
    long long num = 0;

    int L[n1];
    int R[n2];

    for (i = 0; i < n1; i++) 
        L[i] = a[left + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = a[mid + 1+ j]; 
  
    //for (i = 0; i < n1; i++) 
    //    cout<<L[i]<<" ";
    //cout<<endl;

    i = 0; 
    j = 0; 
    k = left; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            a[k] = L[i]; 
            i++; 
        } 
        else
        { 
            num = num + (n1 - i);
            a[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) 
    { 
        a[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) 
    { 
        a[k] = R[j]; 
        j++; 
        k++; 
    } 
    return num;
}
/*
long long get_number_of_inversions(vector<int> a, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, left, ave);
  number_of_inversions += get_number_of_inversions(a, ave+1, right);
  number_of_inversions += merge(a, left, ave, right);
  return number_of_inversions;
}*/

long long mergesort(int a[], int left, int right) 
{ 
    int mid;
    long long inv_count = 0; 
    if (right > left) { 
    
        mid = left + (right - left) / 2; 
        inv_count += mergesort(a, left, mid); 
        inv_count += mergesort(a, mid + 1, right); 
        inv_count += merge(a, left, mid, right); 
    } 
    return inv_count; 
} 

int main() {
  int n;
  std::cin >> n;
  int a[n];
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  //vector<int> b(a.size());
  std::cout << mergesort(a, 0, n-1) << '\n';
}
