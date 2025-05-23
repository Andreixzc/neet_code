#include <bits/stdc++.h>
using namespace std;

// Include your two pointers implementation
#include "two_pointers_template.cpp"

void test_two_pointers() {
    // Test case 1: Pair exists
    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
    int target1 = 9;
    assert(has_pair_with_sum(nums1, target1) && "Failed to find existing pair!");
    
    // Test case 2: Pair doesn't exist
    vector<int> nums2 = {1, 2, 3, 4, 5, 6, 7};
    int target2 = 15;
    assert(!has_pair_with_sum(nums2, target2) && "Incorrectly found non-existent pair!");
    
    // Test case 3: Pair at edges
    vector<int> nums3 = {1, 2, 3, 4, 5, 6, 7};
    int target3 = 8;
    assert(has_pair_with_sum(nums3, target3) && "Failed to find pair at edges!");
    
    // Test case 4: Empty array
    vector<int> nums4 = {};
    int target4 = 10;
    assert(!has_pair_with_sum(nums4, target4) && "Incorrectly handled empty array!");
    
    // Test case 5: Duplicate elements
    vector<int> nums5 = {1, 2, 3, 3, 4, 5};
    int target5 = 6;
    assert(has_pair_with_sum(nums5, target5) && "Failed to handle duplicate elements!");
    
    cout << "All two pointers tests passed!" << endl;
}

int main() {
    test_two_pointers();
    return 0;
}