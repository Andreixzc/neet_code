#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

int characterReplacement(string s, int k) {
    unordered_map<char, int> mymap;
    int maxFreq = 0;
    int left = 0;
    int ans = 0;
    for (int right = 0; right < s.length(); right++) {
        mymap[s[right]]++;
        maxFreq = max(maxFreq, mymap[s[right]]);
        if ((right - left) + 1 - maxFreq > k) {
            while ((right - left) + 1 - maxFreq > k) {
                mymap[s[left]]--;
                left++;
            }
        }
        ans = max(ans, (right - left) + 1);
    }
    return ans;
}
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << characterReplacement("AAABABB", 1) << endl;

    return 0;
}
