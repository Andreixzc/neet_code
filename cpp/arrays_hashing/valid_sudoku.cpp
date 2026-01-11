#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
bool isValidSudoku(vector<vector<char>>& board) {
    unordered_map<int, unordered_set<char>> block_map;
    unordered_map<int, unordered_set<char>> col_map;
    unordered_map<int, unordered_set<char>> row_map;

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            char current = board[i][j];
            if (current == '.') continue;

            int block = (i / 3) * 3 + (j / 3);

            if (row_map[i].count(current)) return false;
            if (col_map[j].count(current)) return false;
            if (block_map[block].count(current)) return false;

            row_map[i].insert(current);
            col_map[j].insert(current);
            block_map[block].insert(current);
        }
    }
    return true;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
