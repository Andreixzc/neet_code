#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
#include <vector>
#include <string>

bool isAnagram(std::string s, std::string t) {
    if (s.length() != t.length()) return false;
    const int ALPHABET_SIZE = 26;
    std::vector<int> first(ALPHABET_SIZE, 0);
    std::vector<int> second(ALPHABET_SIZE, 0);
    for (int i = 0; i < s.length(); i++) {
        first[s[i] - 'a']++;
        second[t[i] - 'a']++;
    }
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (first[i] != second[i]) return false;
    }

    return true;
}




int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}

