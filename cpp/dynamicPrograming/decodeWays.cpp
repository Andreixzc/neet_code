#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

int dp(string s, string partition, int start, int end, unordered_set<string>& memo) {
    if (start >= s.length()) {
        cout << partition.substr(0, partition.length() - 1) << endl;
        return 1;
    }

    if (memo.find(partition) != memo.end()) {
        return 0;
    }
    memo.insert(partition);

    int result = 0;

    string oneChar = s.substr(start, 1);
    if (oneChar[0] != '0') {
        int val = stoi(oneChar);
        if (val >= 1 && val <= 26) {
            result += dp(s, partition + oneChar + ",", start + 1, end, memo);
        }
    }

    if (start + 1 < s.length()) {
        string twoChar = s.substr(start, 2);
        if (twoChar[0] != '0') {
            int val = stoi(twoChar);
            if (val >= 1 && val <= 26) {
                result += dp(s, partition + twoChar + ",", start + 2, end, memo);
            }
        }
    }

    return result;
}

int numDecodings(string s) {
    unordered_set<string> memo;
    return dp(s, "", 0, 0, memo);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s = "06";
    cout << numDecodings(s) << endl;
    return 0;
}
