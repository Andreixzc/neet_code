#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
bool isValidSudoku(vector<vector<char>>& board) {
    unordered_map<int, unordered_set<char>> colSet;
    unordered_map<int, unordered_set<char>> rowSet;
    unordered_map<int, unordered_set<char>> boxSet;

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == '.') continue;
            if (colSet[j].count(board[i][j])) return false;
            if (rowSet[i].count(board[i][j])) return false;
            if (boxSet[(i / 3) * 3 + (j / 3)].count(board[i][j])) return false;
            colSet[j].insert(board[i][j]);
            rowSet[i].insert(board[i][j]);
            boxSet[(i / 3) * 3 + (j / 3)].insert(board[i][j]);
        }
    }

    return true;
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<char>> board = { { '5', '3', '.', '.', '7', '.', '.', '.', '.' },
                                   { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
                                   { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
                                   { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
                                   { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
                                   { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
                                   { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
                                   { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
                                   { '.', '.', '.', '.', '8', '.', '.', '7', '9' } };

    for (int i = 0; i < board.size(); i++) {

        for (int j = 0; j < board[i].size(); j++) {

            cout << board[j][i];
        }
        cout << endl;
    }
    // cout << isValidSudoku(board) << endl;
    return 0;
}
