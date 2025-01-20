#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

bool isPalindrome(string s) {
    int i = 0;
    int j = s.length() - 1;
    while (i < j) {
        if (!isalnum(s[i])) {
            i++;
            continue;
        }
        if (!isalnum(s[j])) {
            j--;
            continue;
        }
        if (s[i] >= 65 && s[i] <= 90) s[i] = s[i] + 32;
        if (s[j] >= 65 && s[j] <= 90) s[j] = s[j] + 32;
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s = "0P";
    cout << isPalindrome(s) << endl;
    return 0;
}
