#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

int dp(vector<int>& memo, int n) {
    if (memo[n] != -1) return memo[n];
    return memo[n] = dp(memo, n - 1) + dp(memo, n - 2);
}
int climbStairsRecursive(int n) {
    vector<int> memo(n + 1, -1);
    memo[0] = 0;
    memo[1] = 1;
    memo[2] = 2;
    return dp(memo, n);
}
int climbStairs(int n) {
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << climbStairsRecursive(6) << endl;
    return 0;
}
