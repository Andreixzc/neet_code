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

string longestPalindrome(string s) {
    int n = s.length();
    vector<vector<bool>> dp(n, vector<bool>(n));
    int max_len = -1;

    for (int i = 0; i < dp.size(); i++) {
        for (int j = 0; j < dp[i].size(); j++) {
            string current_str = s.substr(i, (j - i) + 1);
            int current_len = (j - i) + 1;
            if (isPalindrome(current_str)) {
                dp[i][j] = true;
                max_len = max(max_len, current_len);
            } else {
                dp[i][j] = false;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (dp[i][j] && (j - i + 1) == max_len) {
                return s.substr(i, j - i + 1);
            }
        }
    }

    return "" + s[0];
}

int main() {
    // max_palindrome(0, n -1) = max (palindrome(left++,right) palindrome(left, right--))
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s = "babad";

    cout << longestPalindrome(s) << endl;

    return 0;
}
