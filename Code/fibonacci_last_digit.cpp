#include <iostream>
#include <cassert>
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

int fibonaccild_fast(int n) {
    if (n <= 1)
        return n;
    
    int curr = 0;
    int pre1 = 1;
    int pre2 = 0;
    
    for (int i=2; i<=n;++i){
        curr = (pre1 + pre2) % 10;
        pre2 = pre1 % 10;
        pre1 = curr % 10;
    }
    return curr;
}

void test_solution() {
    assert(fibonaccild_fast(3) == 2);
    assert(fibonaccild_fast(200) == 5);
    for (int n = 0; n < 20; ++n)
        assert(fibonaccild_fast(n) == get_fibonacci_last_digit_naive(n));
}


int main() {
    int n;
    std::cin >> n;
    //test_solution();
    int c = fibonaccild_fast(n);
    std::cout << c << '\n';
    return 0;
    }
