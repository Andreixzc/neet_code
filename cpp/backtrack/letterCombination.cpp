#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

vector<string> mapping = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

void dfs(string& digits, int i, string current, vector<string>& result) {

    if (i == digits.size()) {
        result.push_back(current);
        return;
    }
    // digits = "23";
    // i = 0;
    int index = digits[i] - '0';
    string letters = mapping[index];
    // letters = "abc";

    for (int j = 0; j < letters.length(); j++) {
        dfs(digits, i + 1, current + letters[j], result);
    }
}
vector<string> letterCombinations(string digits) {

    vector<string> result;
    if (!digits.empty()) dfs(digits, 0, "", result);
    return result;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string digits = "23";
    int index = digits[0] - '0';
    cout << index << endl;
    cout << mapping[index] << endl;

    return 0;
}
