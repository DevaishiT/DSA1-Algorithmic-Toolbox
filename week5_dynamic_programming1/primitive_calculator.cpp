#include <bits/stdc++.h>

using namespace std;

/*
vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}
*/

void output_sequence(vector<int> &sequence, vector<int> &sizes, int num)
{
  sequence.push_back(num);
  if (num == 1) return;

  if (num%3 == 0 && (sizes[num - 1] == sizes[num/3 - 1] + 1))
     output_sequence(sequence, sizes, num/3);

  else if (num%2 == 0 && (sizes[num - 1] == sizes[num/2 - 1] + 1))
    output_sequence(sequence, sizes, num/2);

  else output_sequence(sequence, sizes, num - 1);
  
  return;
}

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  //if (n == 0) return sequence;
  if (n == 1)
  {
    sequence.push_back(1);
    return sequence;
  }

  int num;
  vector<int> sizes(n,INT_MAX);
  sizes[0] = 0;
  for(int i = 1; i < n; i++)
  {
      num = i+1;
      if( num%3 == 0)
        sizes[i] = min(sizes[i], sizes[(num/3) - 1]);

      if( num%2 == 0)
        sizes[i] = min(sizes[i], sizes[(num/2) - 1]);

      sizes[i] = min(sizes[i], sizes[i - 1]);
      sizes[i]++;
  }
  //cout<<sizes[n-1]<<endl;
  output_sequence(sequence, sizes, n);
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  if(n == 0)
  {
    cout<<"0"<<endl;
    return 0;
  }
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
  return 0;
}
