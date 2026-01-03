#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
bool isAnagram(string s, string t) {

    if (s.length() != t.length()) return false;
    unordered_map<char, int> mymap;
    for (int i = 0; i < s.length(); i++) {
        mymap[t[i]]--;
        mymap[s[i]]++;
    }

    for (auto element : mymap)
        if (element.second != 0) return false;
    return true;
}
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    string a = "racecar";
    string b = "carrace";
    cout << isAnagram(a, b) << endl;

    return 0;
}
