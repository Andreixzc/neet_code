#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
int dp(vector<int>& costs, vector<int>& memo, int i) {
    if (i >= costs.size()) return 0;
    if (memo[i] != -1) return memo[i];

    memo[i] = costs[i] + min(dp(costs, memo, i + 1), dp(costs, memo, i + 2));
    return memo[i];
}

int minCostClimbingStairsRecursive(vector<int>& costs) {
    vector<int> memo(costs.size(), -1);
    return min(dp(costs, memo, 0), dp(costs, memo, 1));
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
    vector<int> costs = { 1, 2, 1, 2, 1, 1, 1, 1, 2, 2, 3, 3, 4, 1, 2, 2, 3, 3, 1, 2, 3, 1, 1, 1,
                          2, 2, 3, 3, 4, 1, 2, 2, 3, 3, 1, 2, 3, 1, 1, 1, 2, 2, 3, 3, 4, 1, 2, 2,
                          3, 3, 1, 2, 3, 1, 1, 1, 2, 2, 3, 3, 4, 1, 2, 2, 3, 3, 1, 2, 3, 1, 3 };
    cout << minCostClimbingStairs(costs) << endl;
    cout << minCostClimbingStairsRecursive(costs) << endl;
    return 0;
}
