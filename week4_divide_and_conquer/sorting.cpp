#include <bits/stdc++.h>

using namespace std;

int test_partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void test_randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int m = test_partition2(a, l, r);

  test_randomized_quick_sort(a, l, m - 1);
  test_randomized_quick_sort(a, m + 1, r);
}


pair<int, int> partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  int k = l;
  int temp = 0;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] < x) {
      j++;
      k++;
      int temp = a[i];
      a[i] = a[k];
      a[k] = a[j];
      a[j] = temp;
      
    }
    else if (a[i] == x) {
      k++;
      swap(a[i], a[k]);
    }
  }
  swap(a[l], a[j]);

  return make_pair(j,k);
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  pair<int, int> m = partition2(a, l, r);

  randomized_quick_sort(a, l, m.first - 1);
  randomized_quick_sort(a, m.second + 1, r);
}

void test_solution()
{
	int k = 0;
	while(k++ < 100)
	{
		int n = rand()%10;
		vector<int> v;
		for(int i=0; i<n; i++) 
			v.push_back(rand()%100);

		vector<int> v1 = v;
		randomized_quick_sort(v1,0,n-1);
		vector<int> v2 = v;
		test_randomized_quick_sort(v2,0,n-1);

		for(int i=0; i<n; i++)
		{
			if (v1[i] != v2[i])
			{
				cout<<n<<endl;
				for(int i=0; i<n;i++) cout<<v[i]<<" ";
				cout<<endl<<endl;
				for(int i=0; i<n;i++) cout<<v1[i]<<" ";
				cout<<endl<<endl;
				for(int i=0; i<n;i++) cout<<v2[i]<<" ";
				cout<<endl<<endl;
				return;
			}
		}
	}
	return;	
}

int main() {
  
  // srand(time(NULL));
  // test_solution();

  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
  return 0;
}
