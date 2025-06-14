#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

bool isPalindrome(string s) {
    int l = 0;
    int r = s.length() - 1;
    while (l <= r) {
        if (s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

void dfs(vector<vector<string>>& ans, vector<string>& current, int start, string s) {
    if (start == s.length()) {
        ans.push_back(current);
        return;
    }

    for (int i = start; i < s.length(); i++) {
        string substring = s.substr(start, i - start + 1);
        if (isPalindrome(substring)) {
            current.push_back(substring);
            dfs(ans, current, i + 1, s);
            current.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> current;
    dfs(ans, current, 0, s);
    return ans;
}

int main() {
    ios::sync_with_stdio(0); // Typically 0 for faster I/O
    cin.tie(0);

    string s = "radar";
    vector<vector<string>> result = partition(s);

    cout << "Partitions for \"" << s << "\":" << endl;
    for (auto& partition : result) {
        cout << "[";
        for (int i = 0; i < partition.size(); i++) {
            cout << "\"" << partition[i] << "\"";
            if (i < partition.size() - 1) cout << ",";
        }
        cout << "]" << endl;
    }

    return 0; // Fixed: should be 0 for success
}
