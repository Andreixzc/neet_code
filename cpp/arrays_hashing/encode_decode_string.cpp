#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

string encode(vector<string>& strs) {
    string encoded;
    for (int i = 0; i < strs.size(); i++) {
        encoded += to_string(strs[i].length());
        encoded += "@";
        encoded += strs[i];
    }
    return encoded;
}

vector<string> decode(string s) {
    int j = 0;
    string tmp = "";
    vector<string> ans;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '@') {
            int len = stoi(tmp);
            string decoded = "";
            i++;
            for (int k = 0; k < len; k++) {
                decoded += s[i + k];
            }
            ans.push_back(decoded);
            i += len;
            tmp = "";
        }
        tmp += s[i];
    }
    return ans;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<string> input = { "Hello", "World", "djsjdhuhsd" };
    cout << encode(input) << endl;
    vector<string> ans = decode(encode(input));
    for (string s : ans) cout << s << endl;

    return 0;
}
