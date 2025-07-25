#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

bool isPalindrome(string s) {

    int l = 0;
    int r = s.length() - 1;

    while (l < r) {
        if (s[l] != s[r]) return false;
        l++;
        r--;
    }

    return true;
}
int countSubstrings(string s) {

    int n = s.length();
    int ans = 0;
    vector<vector<bool>> dp(n, vector<bool>(n));

    for (int i = 0; i < dp.size(); i++) {
        for (int j = 0; j < dp[i].size(); j++) {
            string currentString = s.substr(i, j - i + 1);
            if (isPalindrome(currentString)) {
                dp[i][j] = true;
                cout << currentString << endl;

            } else {
                dp[i][j] = false;
            }
        }
    }
    for (int i = 0; i < dp.size(); i++) {
        for (int j = i; j < dp[i].size(); j++) {
            if (dp[i][j]) ans++;
        }
    }

    return ans;
}
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << countSubstrings("radar") << endl;

    return 0;
}
