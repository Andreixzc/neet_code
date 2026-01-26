#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> mymap;
    int start = 0;
    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
        if (mymap.find(s[i]) != mymap.end() && mymap[s[i]] >= start) {
            start = mymap[s[i]] + 1;
        }
        mymap[s[i]] = i;
        ans = max(ans, i - start + 1);
    }

    return ans;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
