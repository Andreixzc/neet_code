#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
#include <string>
using namespace std;

bool isPalindrome(string s) {
    int l = 0;
    int r = s.length() - 1;

    while (l < r) {
        while (l < r && !((s[l] >= 'a' && s[l] <= 'z') || (s[l] >= 'A' && s[l] <= 'Z') ||
                          (s[l] >= '0' && s[l] <= '9'))) {
            l++;
        }
        while (r > l && !((s[r] >= 'a' && s[r] <= 'z') || (s[r] >= 'A' && s[r] <= 'Z') ||
                          (s[r] >= '0' && s[r] <= '9'))) {
            r--;
        }

        char cl = s[l];
        char cr = s[r];

        if (cl >= 'A' && cl <= 'Z') cl += 32;
        if (cr >= 'A' && cr <= 'Z') cr += 32;

        if (cl != cr) return false;

        l++;
        r--;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s = "Was it a car or a cat I saw?";
    cout << s[s.length() - 1] << endl;
    isPalindrome(s);

    return 0;
}
