#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

int minCostClimbingStairs(vector<int>& costs) {
    int n = costs.size();

    vector<int> dp(n);

    dp[0] = costs[0];
    dp[1] = costs[1];

    for (int i = 2; i <= costs.size(); i++) dp[i] = costs[i] + min(dp[i - 1], dp[i - 2]);

    return dp[n];
}
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> costs = { 1, 2, 1, 2, 1, 1, 1 };
    cout << minCostClimbingStairs(costs) << endl;

    return 0;
}
