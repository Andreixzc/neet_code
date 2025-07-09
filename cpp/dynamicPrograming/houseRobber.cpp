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

int rob(vector<int>& nums) {
    vector<int> memo(nums.size(), -1);
    return dp(nums, memo, 0);
}
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
