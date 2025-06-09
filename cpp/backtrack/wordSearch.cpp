#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
vector<vector<int>> adj = { { 0, 1 }, { 0, -1 }, { -1, 0 }, { 1, 0 } };

bool dfs(vector<vector<char>>& board,
         string word,
         string currentWord,
         int currentIndex,
         pair<int, int> coords) {
    char tmp = board[coords.first][coords.second];
    board[coords.first][coords.second] = '*';
    if (currentWord == word) return true;
    if (currentWord.length() > word.length()) return false;

    for (int i = 0; i < adj.size(); i++) {
        int newRow = coords.first + adj[i][0];
        int newCol = coords.second + adj[i][1];
        if (newRow < 0 || newRow >= board.size() || newCol < 0 || newCol >= board[0].size())
            continue;
        if (board[newRow][newCol] == word[currentIndex]) {
            if (dfs(board,
                    word,
                    currentWord + board[newRow][newCol],
                    currentIndex + 1,
                    { newRow, newCol })) {
                board[coords.first][coords.second] = tmp;
                return true;
            }
        }
    }
    board[coords.first][coords.second] = tmp;
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    string currentWord = "";
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == word[0]) {
                if (dfs(board, word, currentWord + board[i][j], 1, { i, j })) {
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
    vector<vector<int>> matriz = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
    return 0;
}
