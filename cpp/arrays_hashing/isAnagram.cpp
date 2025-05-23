#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    vector<int> ascii(26);

    for (int i = 0; i < s.size(); i++) {
        ascii[s[i] - 97]++;
        ascii[t[i] - 97]--;
    }

    for (int i = 0; i < ascii.size(); i++) {
        if (ascii[i] != 0) return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << isAnagram("hue", "ueh") << endl;
    return 0;
}
