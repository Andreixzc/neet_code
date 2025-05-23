#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

void dfs(int openCount, int closeCount, string current, int n, vector<string>& ans) {

    if (openCount == closeCount && openCount + closeCount == 2 * n) {
        ans.push_back(current);
        return;
    }
    if (openCount < n) dfs(openCount + 1, closeCount, current + '(', n, ans);
    if (closeCount < openCount) dfs(openCount, closeCount + 1, current + ')', n, ans);
}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    string start = "(";
    dfs(1, 0, start, n, ans);
    return ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<string> ans;
    ans = generateParenthesis(10000);
    for (auto& element : ans) cout << element << endl;

    return 0;
}
