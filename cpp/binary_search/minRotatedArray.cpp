#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

int findMin(vector<int>& nums) {

    int left = 0;
    int right = nums.size() - 1;
    while (left < right) {
        int mid = (right + left) / 2;
        if (nums[mid] > nums[right])
            left = mid + 1;
        else
            right = mid;
    }
    return nums[left];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> input = { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, -2,
                          -1, 0,  1,  2,  3,  4,  5,  6,  7,  8,  9 };

    cout << findMin(input) << endl;

    return 0;
}
