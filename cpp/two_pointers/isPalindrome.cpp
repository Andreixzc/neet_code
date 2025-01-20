#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

bool isPalindrome(string s) {
    int i = 0;
    int j = s.length();
    while (i < j) {
        if (s[i] == ' ') i++;
        if (s[j] == ' ') j--;
        continue;
        else {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}

