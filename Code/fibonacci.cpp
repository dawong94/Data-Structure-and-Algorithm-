#include <iostream>
#include <cassert>

// Xiao wang

int fibonacci_naive(int n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

int fibonacci_fast(int n) {
    // write your code here
    if (n <= 1)
        return n;
    
    int fn = 0;
    int f1 = 1;
    int f2= 0;
    for (int i = 2; i <= n; ++i) {
        fn = f1+f2 ;
        f2 = f1;
        f1 = fn;
        
    }
    
    return fn;
    
}

void test_solution() {
    assert(fibonacci_fast(3) == 2);
    assert(fibonacci_fast(10) == 55);
    for (int n = 0; n < 20; ++n)
        assert(fibonacci_fast(n) == fibonacci_naive(n));
}

int main() {
    int n = 5;
    std::cin >> n;
    
    //test_solution();
    std::cout << fibonacci_fast(n) << '\n';
    return 0;
}
