#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

vector<string> digits = { "1", "2", "3" };
void dfs(vector<string>& result, string current, int n, int control) {
    if (control >= n) {
        result.push_back(current);
        return;
    }
    for (int i = 0; i < digits.size(); i++) {
        dfs(result, current + digits[i], n, control + 1);
    }
}
vector<string> generate(int n) {
    vector<string> result;
    dfs(result, "", n, 0);

    return result;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
