#include <iostream>
#include <vector>
#include <utility> 
#include <algorithm>

using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  double weight = 0.0;

  vector<pair<double, double>> vect;
  for(int i = 0; i < weights.size(); i++)
  {
  	vect.push_back(make_pair(values[i]/(double)weights[i], weights[i]));
  	//cout<<vect[i].first<<": "<<vect[i].second<<endl;
  }
  	
  sort(vect.begin(), vect.end());

  int n = weights.size();
  int index = n - 1;
  while(index >= 0 && weight < capacity)
  {
  	if ((weight + vect[index].second) > capacity)
  	{
  		value += (capacity - weight)*(vect[index].first);
  		weight = capacity;
  	}
  	else
  	{
  		weight += vect[index].second;
  		value += vect[index].first * vect[index].second;
  		index--;
  	}
  }
  // write your code here

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
