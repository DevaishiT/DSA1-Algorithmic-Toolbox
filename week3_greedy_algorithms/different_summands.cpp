#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here
  int leftover = n;
  int candy = 1;
  while (leftover > 0)
  {
  	leftover -= candy;
  	if (leftover < candy+1)
  	{
  		candy += leftover;
  		summands.push_back(candy);
  		return summands;
  	}
  	summands.push_back(candy++);
  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
