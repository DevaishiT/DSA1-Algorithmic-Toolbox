#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long int MaxPairwiseProduct(const std::vector<int>& numbers) {
    
    int max_index1 = -1;
    int max_index2 = -1;
    
    for(int i=0 ;i<numbers.size(); i++) {
    	if (max_index1 == -1 || numbers[i] > numbers[max_index1])
    	     max_index1 = i;
    }
    
    for(int i=0 ;i<numbers.size(); i++) {
    	if ((i != max_index1) && (max_index2 == -1 || numbers[i] > numbers[max_index2]))
    	     max_index2 = i;
    }
    
    //cout<<max_index1<<"   "<<max_index2<<endl;
    
    /*int max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                numbers[first] * numbers[second]);
        }
    }*/

    long long int max_product = ((long long int) numbers[max_index1]) * numbers[max_index2];
    return max_product;
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
