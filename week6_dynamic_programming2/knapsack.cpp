#include <bits/stdc++.h>

using namespace std;

int optimal_weight(int W, const vector<int> &w) {
  int s = w.size();
  vector<vector<int>> arr(W+1,vector<int>(s+1,0));
  //int arr[W + 1][s + 1] = {0};
  //for(int i=0; i<=W; i++) arr[i][0] = 0;
  //for(int i=0; i<=s; i++) arr[0][s] = 0;

  int temp = 0;

  for(int i=1; i <= W; i++)
  {
  	for(int j=1; j <= s; j++)
  	{
  		//if (i == 1 && j == 1) cout<<w[j]<<"  "<<i<<endl;
  		if (w[j-1] <= i)
  		{
  			//if (i == 1 && j == 1) cout<<"Y"<<endl;
  			temp = arr[i - w[j-1]][j-1] + w[j-1];
  			arr[i][j] = max(temp, arr[i][j-1]);
  		}
  		else arr[i][j] = arr[i][j-1];
  	}
  }

  // for(int i=0; i <= W; i++)
  // {
  // 	for(int j=0; j <= s; j++)
  // 	{
  // 		cout<<arr[i][j]<<"   ";
  // 	}
  // 	cout<<endl;
  // }

  return arr[W][s];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
