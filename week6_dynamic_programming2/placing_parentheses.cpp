#include <bits/stdc++.h>

using namespace std;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

long long get_maximum_value(const string &exp) {
  
  int num = (exp.length() + 1)/2;
  vector<vector<int>> maxi(num, vector<int>(num,0));
  vector<vector<int>> mini(num, vector<int>(num,0));

  int j, a, b, c, d;
  int m, M;

  for(int i=0; i <= num-1; i++)
  	mini[i][i] = maxi[i][i] = exp[2*i] - 48;

  for(int k = 1; k <= num-1; k++)
  {
  	for(int i= 0; i <= num - k - 1; i++)
  	{
  		j = i + k;
  		mini[i][j] = INT_MAX;
  		maxi[i][j] = INT_MIN;
  		for(int p = i; p <= j - 1; p++)
  		{
  			a = eval(mini[i][p],mini[p+1][j],exp[2*p+1]);
  			b = eval(maxi[i][p],mini[p+1][j],exp[2*p+1]);
  			c = eval(mini[i][p],maxi[p+1][j],exp[2*p+1]);
  			d = eval(maxi[i][p],maxi[p+1][j],exp[2*p+1]);

  			m = min(min(a,b),min(c,d));
  			M = max(max(a,b),max(c,d));

  			mini[i][j] = min(mini[i][j], m);
  			maxi[i][j] = max(maxi[i][j], M);
  		}
  	}
  }

  for(int i=0;i<num;i++)
  {
  	for(int j=0;j<num;j++)
  	{
  		cout<<mini[i][j]<<" ";
  	}
  	cout<<endl;
  }
  cout<<endl<<endl;
  for(int i=0;i<num;i++)
  {
  	for(int j=0;j<num;j++)
  	{
  		cout<<maxi[i][j]<<" ";
  	}
  	cout<<endl;
  }

  return maxi[0][num - 1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
