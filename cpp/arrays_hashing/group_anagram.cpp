#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> map;
    vector<vector<string>> ans;

    for (int i = 0; i < strs.size(); i++) {
        vector<int> freq(26, 0);
        for (int j = 0; j < strs[i].size(); j++) {
            freq['z' - strs[i][j]]++;
        }
        string key;
        for (int count : freq) key += to_string(count) + ",";
        map[key].push_back(strs[i]);
    }
    for (auto element : map) {
        ans.push_back(element.second);
    }
    return ans;
}
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<string> words = { "hello", "world", "foo", "bar" };
    groupAnagrams(words);

    return 0;
}
