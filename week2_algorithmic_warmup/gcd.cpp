#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_fast(int a, int b) {
   if (a == 0 && b == 0) return 1;
   if (a < b)
   {
   	int temp = a;
   	a = b;
   	b = temp;
   }
   if (b == 0) return a; 
   return gcd_fast(b, a % b); 
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}
