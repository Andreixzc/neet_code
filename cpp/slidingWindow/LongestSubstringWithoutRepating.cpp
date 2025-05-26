#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

int lengthOfLongestSubstring(string s) {
    unordered_set<char> set;
    int left = 0;
    int right = 0;
    int maxlen = 0;
    int current = 0;
    while (right < s.length()) {
        if (set.find(s[right]) == set.end()) {
            current++;
            set.insert(s[right]);
            right++;
            maxlen = max(maxlen, current);
        } else {
            set.erase(s[left]);
            left++;
            current--;
        }
    }

    return maxlen;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s = "pwwkew";
    cout << lengthOfLongestSubstring(s) << endl;

    return 0;
}
