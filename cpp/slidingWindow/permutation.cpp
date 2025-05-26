#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
bool checkInclusion(string s1, string s2) {
    unordered_map<char, int> s1map;
    unordered_map<char, int> windowMap;
    int left = 0;
    int right = s1.length();
    for (int i = 0; i < s1.length(); i++) {
        s1map[s1[i]]++;
        windowMap[s2[i]]++;
    }
    while (right < s2.length()) {
        if (s1map == windowMap)
            return true;
        else {
            if (windowMap[s2[left]] - 1 == 0) {
                windowMap.erase(s2[left]);
            } else {
                windowMap[s2[left]]--;
            }
            left++;
        }
        windowMap[s2[right]]++;
        right++;
    }
    if (s1map == windowMap) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s1 = "abc";
    string s2 = "lecabee";
    cout << checkInclusion(s1, s2) << endl;

    return 0;
}
