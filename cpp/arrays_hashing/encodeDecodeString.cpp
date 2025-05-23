#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

string encode(vector<string>& strs) {
    string ans = "";

    for (int i = 0; i < strs.size(); i++) {
        ans += to_string(strs[i].size());
        ans += "#";
        for (int j = 0; j < strs[i].size(); j++) ans += strs[i][j];
    }
    return ans;
}

vector<string> decode(string s) {
    vector<string> ans;
    int i = 0;
    while (i < s.length()) {
        string slen = "";
        while (s[i] != '#') {
            slen += s[i];
            i++;
        }
        i++;
        int len = stoi(slen);
        string current = "";
        for (int j = 0; j < len; j++) {
            current += s[i];
            i++;
        }
        ans.push_back(current);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<string> input = { "1,23", "45,6", "7,8,9" };
    string output = encode(input);
    vector<string> out = decode(output);
    for (auto element : out) cout << element << endl;

    return 0;
}
