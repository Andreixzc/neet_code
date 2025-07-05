#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

// recursive approach

int dp(int n, vector<int>& memo) {

    if (n <= 0) return 0;
    if (memo[n] != -1) return memo[n];
    return memo[n] = dp(n - 1, memo) + dp(n - 2, memo);
}

int climbingStairsRec(int n) {
    vector<int> memo(n + 1, -1);
    memo[1] = 1;
    memo[2] = 2;
    return dp(n, memo);
}

// 1d dp:

int climbStairs(int n) {
    if (n <= 2) return n;

    vector<int> stairs(n + 1);
    stairs[1] = 1;
    stairs[2] = 2;

    for (int i = 3; i <= n; i++) stairs[i] = stairs[i - 1] + stairs[i - 2];

    return stairs[n];
}
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << climbStairs(10) << endl;
    cout << climbingStairsRec(10) << endl;

    return 0;
}
