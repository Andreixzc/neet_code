#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
int dp(vector<int>& costs, vector<int>& memo, int i, int total) {
    if (i >= costs.size()) return total;
    if (memo[i] != -1) return memo[i];
    total += costs[i];
    memo[i] = min(dp(costs, memo, i + 1, total), dp(costs, memo, i + 2, total));
    return memo[i];
}
int minCostClimbingStairsRecursive(vector<int>& costs) {
    vector<int> memo(costs.size(), -1);
    return min(dp(costs, memo, 0, 0), dp(costs, memo, 1, 0));
}
int minCostClimbingStairs(vector<int>& costs) {
    int n = costs.size();
    vector<int> dp(n + 1);
    dp[0] = costs[0];
    dp[1] = costs[1];
    for (int i = 2; i < costs.size(); i++) dp[i] = costs[i] + min(dp[i - 1], dp[i - 2]);
    return min(dp[n - 1], dp[n - 2]);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> costs = { 1, 2, 1, 2, 1, 1, 1 };
    cout << minCostClimbingStairs(costs) << endl;
    return 0;
}
