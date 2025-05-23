#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> map;

    for (int i = 0; i < strs.size(); i++) {
        string key = "";
        vector<int> freq(26, 0);
        for (int j = 0; j < strs[i].size(); j++) {
            int index = strs[i][j] - 'a';
            freq[index]++;
        }
        for (int k = 0; k < freq.size(); k++) {
            key += to_string(freq[k]);
            key += '#';
        }
        map[key].push_back(strs[i]);
    }
    vector<vector<string>> ans;
    for (auto [key, value] : map) ans.push_back(value);
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<string> array = { "act", "pots", "tops", "cat", "stop", "hat" };
    auto ans = groupAnagrams(array);

    for (int i = 0; i < ans.size(); i++) {

        for (int j = 0; j < ans[i].size(); j++) { cout << ans[i][j]; }
        cout << endl;
    }

    return 0;
}
