#include <bits/stdc++.h>
using namespace std;

// Include your binary search implementation
#include "binary_search_template.cpp"

void test_binary_search() {
    // Test case 1: Element exists in array
    vector<int> nums1 = {1, 3, 5, 7, 9, 11, 13, 15};
    assert(binary_search(nums1, 7) == 3 && "Failed to find existing element!");
    
    // Test case 2: Element does not exist in array
    vector<int> nums2 = {1, 3, 5, 7, 9, 11, 13, 15};
    assert(binary_search(nums2, 8) == -1 && "Incorrectly found non-existent element!");
    
    // Test case 3: Element at start of array
    vector<int> nums3 = {1, 3, 5, 7, 9, 11, 13, 15};
    assert(binary_search(nums3, 1) == 0 && "Failed to find element at start!");
    
    // Test case 4: Element at end of array
    vector<int> nums4 = {1, 3, 5, 7, 9, 11, 13, 15};
    assert(binary_search(nums4, 15) == 7 && "Failed to find element at end!");
    
    // Test case 5: Empty array
    vector<int> nums5 = {};
    assert(binary_search(nums5, 5) == -1 && "Incorrectly handled empty array!");
    
    // Test case 6: Single element array (found)
    vector<int> nums6 = {5};
    assert(binary_search(nums6, 5) == 0 && "Failed to find element in single-element array!");
    
    // Test case 7: Single element array (not found)
    vector<int> nums7 = {5};
    assert(binary_search(nums7, 7) == -1 && "Incorrectly found element in single-element array!");
    
    cout << "All binary search tests passed!" << endl;
}

int main() {
    test_binary_search();
    return 0;
}