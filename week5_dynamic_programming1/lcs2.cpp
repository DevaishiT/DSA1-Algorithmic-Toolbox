#include <bits/stdc++.h>

using namespace std;
/*
int edit_distance(const string &str1, const string &str2) {
  //write your code here
  int n = str1.length();
  int m = str2.length();

  if (n == 1 && m == 1)
  {
  	if (str1[0] == str2[0]) return 0;
  	else return 1;
  }
  int ed[n+1][m+1] = {0};

  for(int i=0; i<=n;i++) ed[i][0] = i;
  for(int j=0; j<=m;j++) ed[0][j] = j;

  int ins, del, mis;
  for(int i=1; i<=n; i++)
  {
  	for(int j=1; j<=m; j++)
  	{
  		ins = ed[i][j-1] + 1;
  		del = ed[i-1][j] + 1;
  		mis = ed[i-1][j-1] + 1;
		
		if(str1[i - 1] == str2[j - 1])
		{
			//cout<<"y"<<endl;
			ed[i][j] = min(ins, del);
			ed[i][j] = min(ed[i][j], (mis - 1));
		}
		else
		{
			ed[i][j] = min(ins, del);
			ed[i][j] = min(ed[i][j], mis);
		}
  	}
  }

  // for(int i=0; i<=n; i++)
  // {
  // 	for(int j=0; j<=m; j++)
  // 	{
  // 		cout<<ed[i][j]<<"  ";
  // 	}
  // 	cout<<endl;
  // }

  return ed[n][m];
}
*/
int lcs2(vector<int> &a, vector<int> &b) {
  
  int n = a.size();
  int m = b.size();

  int d[n+1][m+1] = {0};

  // for(int i=0; i<=n; i++)
  // {
  // 	for(int j=0; j<=m; j++)
  // 	{
  // 		cout<<d[i][j]<<"  ";
  // 	}
  // 	cout<<endl;
  // }

  for(int i=0; i<=n; i++)
  {
  	for(int j=0; j<=m; j++)
  	{
		if(i == 0 or j == 0)
		{
			d[i][j] = 0;
			continue;
		}

		if(a[i - 1] == b[j - 1])
			d[i][j] = d[i-1][j-1] + 1;
		else
		{
			d[i][j] = max(d[i][j-1], d[i-1][j]);
		}
  	}
  }

  // for(int i=0; i<=n; i++)
  // {
  // 	for(int j=0; j<=m; j++)
  // 	{
  // 		cout<<d[i][j]<<"  ";
  // 	}
  // 	cout<<endl;
  // }

  return d[n][m];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
