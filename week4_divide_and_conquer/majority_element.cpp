#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int my_majority_element(vector<int> &a)
{
  if (a.size() == 0) return -1;
  if (a.size() == 1) return a[0];
  sort(a.begin(),a.end());
  
  int i = 0, temp = 1;
  int len = a.size()/2;
  int prev = -1;
  while (i < a.size())
  {
  	while (a[i] == prev)
  	{
  		i++; temp++; continue;
  	}
  	//cout<<temp<<endl;
  	if(temp > len) return prev;
  	temp = 1;
  	prev = a[i++];
  }
  return -1;
}

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  

  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  //cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
  cout << (my_majority_element(a) != -1) << '\n';
}
