#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
bool checkInclusion(string s1, string s2) {
    unordered_map<char, int> s1_map;
    unordered_map<char, int> window;
    for (char c : s1) s1_map[c]++;

    for (int i = 0; i < s2.length(); i++) {
        window[s2[i]]++;
        if (i >= s1.length()) {
            char firstChar = s2[i - s1.length()];
            window[firstChar]--;
            if (window[firstChar] == 0) window.erase(firstChar);
        }
        if (window == s1_map) return true;
    }
    return false;
}
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
