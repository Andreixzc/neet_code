#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

int rob(vector<int>& nums) {
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    if (nums.size() == 2) return max(dp[0], dp[1]);
    for (int i = 2; i < nums.size(); i++) dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
    return dp[nums.size() - 1];
}
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> input = { 5, 1, 2, 10, 6, 2, 7, 9, 3, 1 };

    cout << rob(input) << endl;

    return 0;
}
