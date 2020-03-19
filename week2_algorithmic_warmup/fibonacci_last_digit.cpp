#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit_fast(int n) {
	// write your code here
    vector<int> fib(n + 2,0);
    fib[0] = 0;
    fib[1] = 1;
    for(int i= 2; i <= n; i++)
    {
    	fib[i] = (fib[i-1] + fib[i-2])%10;
    }
    return fib[n];
}

void test_solution() {
    assert(get_fibonacci_last_digit_fast(3) == 2);
    assert(get_fibonacci_last_digit_fast(10) == 5);
    for (int n = 0; n < 20; ++n)
        assert(get_fibonacci_last_digit_fast(n) == get_fibonacci_last_digit_naive(n));
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
    //test_solution();
    }
