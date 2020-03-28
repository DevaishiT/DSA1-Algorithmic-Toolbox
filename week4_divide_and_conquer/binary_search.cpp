#include <bits/stdc++.h>

using namespace std;

int binary_search(const vector<int> &a, int x) {
  if (a.size() == 0) return -1;
  int left = 0, right = (int)a.size() - 1; 
  int mid = 0;
  while (right >= left)
  {
  	mid = (left + right)/2;
  	if (x == a[mid]) return mid;
  	else if (x < a[mid]) right = mid - 1;
  	else left = mid + 1;
  }
  return -1;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}
/*
void test_solution()
{
	int i = 0;
	while(i++ < 100)
	{
		int n = rand()%100;
		vector<int> v;
		for(int i=0; i<n; i++) 
			v.push_back(rand()%100);
		sort(v.begin(),v.end());
		int x = rand()%100;
		int a = linear_search(v,x);
		int b = binary_search(v,x);
		if (v[a] != v[b])
		{
			cout<<n<<endl;
			for(int i=0; i<n;i++) cout<<v[i]<<" ";
			cout<<endl<<x<<endl;
			cout<<"linear = "<<a<<"  binary = "<<b<<endl;
			return;
		}
	}
	return;	
}
*/

int main() {
  // srand(time(NULL));	
  // test_solution();

  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i]) << ' ';
  }
  return 0;
}
