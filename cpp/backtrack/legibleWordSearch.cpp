#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

vector<vector<char>> board;
string target_word;
vector<vector<int>> directions = { { 0, 1 }, { 0, -1 }, { -1, 0 }, { 1, 0 } };
int rows, cols;

bool dfs(int row, int col, int word_index) {
    if (word_index == target_word.length()) return true;
    if (row < 0 || row >= rows || col < 0 || col >= cols) return false;
    if (board[row][col] != target_word[word_index]) return false;

    char original_char = board[row][col];

    board[row][col] = '*';

    for (auto& dir : directions) {
        int new_row = row + dir[0];
        int new_col = col + dir[1];

        if (dfs(new_row, new_col, word_index + 1)) {
            board[row][col] = original_char;
            return true;
        }
    }

    board[row][col] = original_char;
    return false;
}

bool word_exists(vector<vector<char>>& input_board, string word) {
    board = input_board;
    target_word = word;
    rows = board.size();
    cols = board[0].size();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j] == target_word[0]) {
                if (dfs(i, j, 0)) {
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

    // Example usage
    vector<vector<char>> test_board = { { 'A', 'B', 'C' }, { 'S', 'F', 'C' }, { 'A', 'D', 'E' } };

    string search_word = "ABCCED";

    if (word_exists(test_board, search_word)) {
        cout << "Word found!" << endl;
    } else {
        cout << "Word not found!" << endl;
    }

    return 0;
}
