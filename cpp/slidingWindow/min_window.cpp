#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

string minWindow(string s, string t) {

    unordered_map<char, int> freq, window;

    int left = 0;
    int match = 0;
    string ans = "";

    for (auto c : t) freq[c]++;

    for (int right = 0; right < s.length(); right++) {
        window[s[right]]++;
        if (freq.count(s[right]) && window[s[right]] == freq[s[right]]) match++;
        while (match == freq.size()) {
            string current = s.substr(left, right - left + 1);
            if (ans.empty() || current.length() < ans.length()) ans = current;
            if (freq.count(s[left]) && window[s[left]] == freq[s[left]]) match--;
            window[s[left]]--;
            left++;
        }
    }

    return ans;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
