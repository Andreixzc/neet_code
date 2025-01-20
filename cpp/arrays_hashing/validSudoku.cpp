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
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //  cout << (i/3)*3+(j/3);
}

