#include <bits/stdc++.h>
using namespace std;

// Include your Fibonacci implementation
#include "fibonacci_template.cpp"

void test_fibonacci() {
    // Test known Fibonacci values
    assert(fibonacci(0) == 0 && "F(0) should be 0!");
    assert(fibonacci(1) == 1 && "F(1) should be 1!");
    assert(fibonacci(2) == 1 && "F(2) should be 1!");
    assert(fibonacci(3) == 2 && "F(3) should be 2!");
    assert(fibonacci(4) == 3 && "F(4) should be 3!");
    assert(fibonacci(5) == 5 && "F(5) should be 5!");
    assert(fibonacci(6) == 8 && "F(6) should be 8!");
    assert(fibonacci(7) == 13 && "F(7) should be 13!");
    assert(fibonacci(8) == 21 && "F(8) should be 21!");
    assert(fibonacci(9) == 34 && "F(9) should be 34!");
    assert(fibonacci(10) == 55 && "F(10) should be 55!");
    
    // Test larger value
    assert(fibonacci(20) == 6765 && "F(20) should be 6765!");
    
    cout << "All Fibonacci tests passed!" << endl;
}

int main() {
    test_fibonacci();
    return 0;
}