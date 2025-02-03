#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

void dfs(int open, int close, string current, vector<string> &ans, int n) {
    if (open == close && open + close == 2 * n) {
        ans.push_back(current);
        return;
    }
    if (open < n) dfs(open + 1, close, current + "(", ans, n);
    if (close < open) dfs(open, close + 1, current + ")", ans, n);
}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    dfs(1, 0, "(", ans, n);
    return ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 3;
    vector<string> ans = generateParenthesis(n);
    for (auto element : ans) {
        cout << element << endl;
    }

    return 0;
}
