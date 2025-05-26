#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

int characterReplacement(string s, int k) {
    int left = 0, right = 0;
    map<char, int> freq;
    int maxFreq = 0;
    int maxlen = 0;

    while (right < s.length()) {
        freq[s[right]]++;
        maxFreq = max(freq[s[right]], maxFreq);

        int windowSize = right - left + 1;

        if (windowSize - maxFreq > k) {
            freq[s[left]]--;
            left++;
        }

        maxlen = max(maxlen, right - left + 1);
        right++;
    }

    return maxlen;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s = "ABCCCEFFGGK";
    int k = 2;
    cout << characterReplacement(s, k) << endl;

    return 0;
}
