#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

vector<string> letters = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

void dfs(vector<string>& ans, string digits, string current, int start) {
    if (start == digits.length()) {
        ans.push_back(current);
        return;
    }
    int digit = digits[start] - '0';

    string possibleLetters = letter[digit];

    for (char letter : possibleLetters) {
        dfs(ans, digits, current + letter, start + 1);
    }
}

vector<string> letterCombination(strings digits) {
    vector<string> ans;
    dfs(ans, digits, "", 0);
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string digits = "32123";
    for (char digit : digits) cout << digit - '0' << endl;

    return 0;
}
