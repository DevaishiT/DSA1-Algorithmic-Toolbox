#include <bits/stdc++.h>

using namespace std;

short int dp[100][100][100];

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c, int i, int j, int k)
{
  if (i == -1 || j == -1 || k == -1) return 0;
  if (dp[i][j][k] != -1) return dp[i][j][k];
  else if (a[i] == b[j] && a[i] == c[k])
    dp[i][j][k] = 1 + lcs3(a,b,c,i-1,j-1,k-1);
  else dp[i][j][k] = max(max(lcs3(a,b,c,i-1,j,k), lcs3(a,b,c,i,j-1,k)), lcs3(a,b,c,i,j,k-1));
  return dp[i][j][k];
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }

  for(int i=0; i<an;i++)
  {
  	for(int j=0; j<bn; j++)
  	{
  		for(int k=0; k<cn; k++)
  			dp[i][j][k] = -1;
  	}
  }
  std::cout << lcs3(a, b, c, an-1, bn-1, cn-1) << std::endl;
}
