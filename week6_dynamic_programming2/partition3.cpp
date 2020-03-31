#include <bits/stdc++.h>

using namespace std;

bool rec_partition3(vector<int> &a, int n, int n1, int n2, int n3)
{
    if (n1 == 0 && n2 == 0 && n3 == 0)
        return true;
 
    if (n < 0)
        return false;

    bool A = false;
    if (n1 - a[n] >= 0)
        A = rec_partition3(a, n - 1, n1 - a[n], n2, n3);

    bool B = false;
    if (!A && (n2 - a[n] >= 0))
        B = rec_partition3(a, n - 1, n1, n2 - a[n], n3);
 

    bool C = false;
    if ((!A && !B) && (n3 - a[n] >= 0))
        C = rec_partition3(a, n - 1, n1, n2, n3 - a[n]);

    return A || B || C;
}

int partition3(vector<int> &a, int sum) 
{
  if (a.size() < 3 || sum % 3 != 0) return 0;

  int num = sum/3;

  bool res = rec_partition3(a, a.size() - 1, num, num, num);
  return res;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  std::cin >> n;
  vector<int> A(n);
  int sum = 0;
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
    sum += A[i];
  }
  std::cout << partition3(A, sum) << '\n';
}
