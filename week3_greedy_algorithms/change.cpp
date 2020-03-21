#include <iostream>

using namespace std;

int get_change(int m) {
	//write your code here
	int temp = m;

	int num = temp/10;
	temp -= (temp/10)*10;

	num += temp/5;
	temp -= (temp/5)*5;

	num += temp;

	return num;
}

int main() {
	  int m;
	  std::cin >> m;
	  std::cout << get_change(m) << '\n';
}
