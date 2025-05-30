#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

void dfs(vector<string>& ans, string current, int n) {
    if (current.length() >= n) {
        ans.push_back(current);
        return;
    }
    dfs(ans, current + "0", n);
    dfs(ans, current + "1", n);
}

vector<string> binary(int n) {
    vector<string> ans;
    dfs(ans, "", n);
    return ans;
}
int main() {
    ios::sync_with_stdio(0);

    auto caralho = binary(15);

    for (auto desgraca : caralho) cout << desgraca << endl;

    return 0;
}
