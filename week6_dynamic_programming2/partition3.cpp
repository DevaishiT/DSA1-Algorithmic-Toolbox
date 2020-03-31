#include <bits/stdc++.h>

using namespace std;

bool rec_partition3(vector <int> &a, int n1, int n2, int n3, int s)
{
	if (a[s] <= n1)

}

int partition3(vector<int> &a, int sum) 
{
  if (sum % 3 != 0) return 0;
  int num = sum/3;
  bool res = rec_partition3(a,sum/3,sum/3,sum/3,a.size() - 1);
  return 0;
}

int main() {
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
