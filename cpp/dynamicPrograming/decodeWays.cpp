#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

int dp(string s, int start, unordered_map<int, int>& memo) {

    if (start >= s.length()) return 1;
    if (memo.find(start) != memo.end()) return memo[start];

    int branchResult = 0;

    if (s[start] != '0') {
        int val = s[start] - '0';
        if (val >= 1 && val <= 26) branchResult += dp(s, start + 1, memo);
    }

    if (start < s.length() - 1) {
        if (s[start] != '0') {
            int val = stoi(s.substr(start, 2));
            if (val >= 1 && val <= 26) branchResult += dp(s, start + 2, memo);
        }
    }

    return memo[start] = branchResult;
}

int numDecodings(string s) {
    unordered_map<int, int> memo;
    return dp(s, 0, memo);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str = "1206";

    cout << numDecodings(str) << endl;
    return 0;
}
