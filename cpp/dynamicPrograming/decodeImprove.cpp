#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

int dp(string s, int start, unordered_map<int, int>& memo) {
    if (start >= s.length()) {
        return 1;
    }

    if (memo.find(start) != memo.end()) {
        return memo[start];
    }

    int result = 0;

    string oneChar = s.substr(start, 1);
    cout << oneChar << endl;
    if (oneChar[0] != '0') {
        int val = stoi(oneChar);
        if (val >= 1 && val <= 26) {
            result += dp(s, start + 1, memo);
        }
    }

    if (start + 1 < s.length()) {
        string twoChar = s.substr(start, 2);
        cout << twoChar << endl;
        if (twoChar[0] != '0') {
            int val = stoi(twoChar);
            if (val >= 1 && val <= 26) {
                result += dp(s, start + 2, memo);
            }
        }
    }

    memo[start] = result;
    return result;
}

int numDecodings(string s) {
    unordered_map<int, int> memo;
    return dp(s, 0, memo);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s = "1206";
    cout << numDecodings(s) << endl;
    return 0;
}
