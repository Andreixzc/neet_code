#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

// house rob II
int dp(vector<int>& nums, int start, int end, vector<int>& memo, int i) {
    if (i > end) return 0;
    if (memo[i] != -1) return memo[i];

    return memo[i] =
             max(nums[i] + dp(nums, start, end, memo, i + 2), dp(nums, start, end, memo, i + 1));
}

int rob(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    vector<int> memo1(nums.size(), -1);
    vector<int> memo2(nums.size(), -1);
    return max(dp(nums, 0, nums.size() - 2, memo1, 0), dp(nums, 1, nums.size() - 1, memo2, 1));
}
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> nums = { 3, 4, 3 };
    cout << rob(nums) << endl;

    return 0;
}
