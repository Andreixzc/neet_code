#include <bits/stdc++.h>
using namespace std;

// Include your sliding window implementation
#include "sliding_window_template.cpp"

void test_sliding_window() {
    // Test case 1: Regular array
    vector<int> nums1 = {1, 4, 2, 10, 2, 3, 1, 0, 20};
    int k1 = 4;
    assert(max_subarray_sum(nums1, k1) == 24 && "Maximum sum subarray is incorrect!");
    
    // Test case 2: Array size equals window size
    vector<int> nums2 = {1, 4, 2, 10};
    int k2 = 4;
    assert(max_subarray_sum(nums2, k2) == 17 && "Maximum sum subarray is incorrect!");
    
    // Test case 3: Negative numbers
    vector<int> nums3 = {-1, -4, -2, -10, -2, -3, -1, 0, -20};
    int k3 = 3;
    assert(max_subarray_sum(nums3, k3) == -1 && "Maximum sum subarray is incorrect!");
    
    // Test case 4: Mixed positive and negative
    vector<int> nums4 = {5, -2, 7, 1, -5, 8, -3, 6};
    int k4 = 3;
    assert(max_subarray_sum(nums4, k4) == 10 && "Maximum sum subarray is incorrect!");
    
    cout << "All sliding window tests passed!" << endl;
}

int main() {
    test_sliding_window();
    return 0;
}