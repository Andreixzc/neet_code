#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
int findMin(vector<int>& nums) {

    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = (right + left) / 2;
        if (nums[left] <= nums[right])
            return nums[left];
        else if (nums[mid] >= nums[left])
            left = mid + 1;
        else
            right = mid;
    }
    return 0;
}
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
