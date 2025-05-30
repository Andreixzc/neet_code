#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

void dfs(vector<string>& ans, int open, int close, int n, string current) {

    if (open == close && (open + close) == 2 * n) {
        ans.push_back(current);
        return;
    }
    if (open < n) dfs(ans, open + 1, close, n, current + "(");
    if (close < open) dfs(ans, open, close + 1, n, current + ")");
}

vector<string> generateParenthesis(int n) {

    vector<string> ans;
    string current = "(";
    dfs(ans, 1, 0, n, current);
    return ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    auto caralho = generateParenthesis(2);
    for (auto desgraca : caralho) cout << desgraca << endl;

    return 0;
}
