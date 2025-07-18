#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

int dp(vector<int>& costs, vector<int>& memo, int i) {

    if (memo[i] != -1) return memo[i];
    return memo[i] = costs[i] + min(dp(costs, memo, i - 1), dp(costs, memo, i - 2));
}

int minCostClimbingStairsRecursive(vector<int>& costs) {
    vector<int> memo(costs.size(), -1);
    memo[0] = costs[0];
    memo[1] = costs[1];

    return min(dp(costs, memo, costs.size() - 1), dp(costs, memo, costs.size() - 2));
}
int minCostClimbingStairs(vector<int>& costs) {
    vector<int> dp(costs.size());
    dp[0] = costs[0];
    dp[1] = costs[1];
    for (int i = 2; i <= dp.size(); i++) dp[i] = min(dp[i - 1] + costs[i], dp[i - 2] + costs[i]);
    return dp[dp.size()];
}
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> costs = { 1, 2, 3 };
    cout << minCostClimbingStairsRecursive(costs) << endl;

    return 0;
}
