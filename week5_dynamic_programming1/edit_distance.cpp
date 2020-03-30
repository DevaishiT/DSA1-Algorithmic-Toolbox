#include <bits/stdc++.h>

using namespace std;

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

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
