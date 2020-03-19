#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
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
   //return a % b == 0 ? b : gcd_fast(b % a, a);
}

long long lcm_fast(long long a, long long b) {
   return a * b / gcd_fast(a,b);
}

/*void test_solution() {
    assert(lcm_fast(6,8) == 24);
    assert(lcm_fast(761457,614573) == 467970912861);
    while(1) {
       int a = rand()%10 + 1;
       int b = rand()%10 + 1;
       if (lcm_fast(a, b) != lcm_naive(a, b)) {
       	   cout<<a<<"    "<<b<<endl;
       	   break;
       }
       else cout<<"y"<<endl;
    }
}*/

int main() {
  //srand(time(NULL));
  //test_solution();
  long long a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
