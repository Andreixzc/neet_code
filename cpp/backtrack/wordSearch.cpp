#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

vector<vector<int>> directions = { { 0, 1 }, { 0, -1 }, { -1, 0 }, { 1, 0 } };
vector<vector<char>> input_board;
string input_word;

bool dfs(string current, int index, int row, int col) {
    if (index > input_word.length()) return false;
    if (current == input_word) return true;
    for (const auto& element : directions) {
        char original = input_board[row][col];
        int newRow = row + element[0];
        int newCol = col + element[1];
        if (newRow < 0 || newRow >= input_board.size() || newCol < 0 ||
            newCol >= input_board[0].size())
            continue;
        if (input_board[newRow][newCol] == input_word[index]) {
            input_board[row][col] = '*';
            if (dfs(current + input_board[newRow][newCol], index + 1, newRow, newCol)) {
                input_board[row][col] = original;
                return true;
            }
            input_board[row][col] = original;
        }
    }
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    input_board = board;
    input_word = word;
    string currentWord = "";

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == word[0]) {
                if (dfs(currentWord + board[i][j], 1, i, j)) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<char>> test_board = { { 'A', 'B', 'C' }, { 'S', 'F', 'C' }, { 'A', 'D', 'E' } };
    string search_word = "ABCCED";
    cout << exist(test_board, search_word) << endl;

    for (const auto& element : directions) {
        cout << element[0];
        cout << element[1];
    }
    return 0;
}
