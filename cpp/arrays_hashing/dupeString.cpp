#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

string remove(string str) {

    string ans = "";

    for (int i = 0; i < str.length(); i++) {
        for (int j = i + 1; j < str.length(); j++) {
            int c = 0;
            if (str[i] == str[j]) { c++; }
            ans += str.substr(i, c);
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a = "abbaca";
    cout << remove(a) << endl;
    return 0;
}
