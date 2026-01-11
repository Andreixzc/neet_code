#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

bool isPalindrome(string s) {
    int left = 0;
    int right = s.length() - 1;
    while (left < right) {
        while (left < right && !isalpha(s[left])) left++;
        while (left < right && !isalpha(s[right])) right--;
        if (tolower(s[left]) != tolower(s[right])) return false;
        left++;
        right--;
    }
    return true;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    string s = "tab a cat";
    cout << isPalindrome(s) << endl;

    return 0;
}
