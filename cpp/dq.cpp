#include <deque>
#include <iostream>
#include <vector>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq; // stores INDICES, not values
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        // Remove indices outside the window from front
        if (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front(); // O(1) - window slides forward
        }

        // Remove smaller elements from back (maintain decreasing order)
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back(); // O(1) - remove useless elements
        }

        dq.push_back(i); // O(1) - add current element

        // Add max to result (front of deque is always max)
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}

int main() {
    vector<int> nums = { 1, 3, -1, -3, 5, 3, 6, 7 };
    int k = 3;

    vector<int> result = maxSlidingWindow(nums, k);

    for (int x : result) {
        cout << x << " "; // Output: 3 3 5 5 6 7
    }

    return 0;
}
