#include <bits/stdc++.h>

using namespace std;

int get_change(int m) {
  //write your code here
  vector<int> change(m+1);
  int num;
  change[0] = 0;
  for(int i=1; i <=m; i++)
  {
  	if (i >= 4) 
  	{
  		num = min(change[i-1],change[i-3]);
  		change[i] = min(num,change[i-4]) + 1;
  	}
  	else if (i >= 3)
  		change[i] = min(change[i-1],change[i-3]) + 1;
 	else change[i] = change[i-1] + 1;
  }
  return change[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
