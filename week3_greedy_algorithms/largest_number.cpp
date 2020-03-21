#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool sort_function (string s1, string s2)
{
  for(int i = 0; i<s1.size() || i<s2.size(); i++)
  {
    if (i < s2.size() && i < s1.size())
    {
      if (s1[i] > s2[i]) return true;
      else if (s1[i] < s2[i]) return false;
    }
    else if (i<s1.size()) return false;
    else return true;
  }
  //return true;
}

string largest_number(vector<string> a) {
  
  sort(a.begin(),a.end(),sort_function);

  stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
