#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

int dp(vector<int>& nums, vector<int>& memo, int i) {

    if (i >= nums.size()) return 0;
    if (memo[i] != -1) return memo[i];

    return memo[i] = max(nums[i] + dp(nums, memo, i + 2), dp(nums, memo, i + 1));
}

int robRecursive(vector<int>& nums) {
    vector<int> memo(nums.size(), -1);
    return dp(nums, memo, 0);
}

int rob(vector<int>& nums) {
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    dp[1] = max[nums[0], nums[1]];
    for (int i = 2; i < nums.size(); i++) dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);

    return dp[nums.size() - 1];
}
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
