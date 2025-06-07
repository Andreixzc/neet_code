#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

void dfs(vector<vector<int>>& ans,
         vector<int>& candidates,
         vector<int>& current,
         int target,
         int sum,
         int start) {

    if (sum == target) {
        ans.push_back(current);
        return;
    }
    if (sum > target) return;

    // o ponto de pular a duplicata, é pra não começar nenhum node pai com o mesmo valor que um pai
    // anterior porque só poderia gerar valores repetidos.
    for (int i = start; i < candidates.size(); i++) {
        if (i > start && candidates[i] == candidates[i - 1]) continue;
        current.push_back(candidates[i]);
        dfs(ans, candidates, current, target, sum + candidates[i], i + 1);
        current.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> current;
    dfs(ans, candidates, current, target, 0, 0);

    return ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
