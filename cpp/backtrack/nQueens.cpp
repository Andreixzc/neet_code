#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

vector<pair<int, int>> coords = { { 0, -1 }, { 0, 1 }, { -1, -1 }, { 1, 1 },
                                  { -1, 0 }, { 1, 0 }, { -1, 1 },  { 1, -1 } };

void placeQueen(vector<string>& current, vector<vector<int>>& aux, int row, int col) {
    current[row][col] = 'Q';
    for (int i = 0; i < coords.size(); i++) {
        pair<int, int> currentCoord = coords[i];
        int cx = row + currentCoord.first;
        int cy = col + currentCoord.second;
        while (cx >= 0 && cx < current.size() && cy >= 0 && cy < current.size()) {
            aux[cx][cy]++;
            cx += currentCoord.first;
            cy += currentCoord.second;
        }
    }
}

void deleteQueen(vector<string>& current, vector<vector<int>>& aux, int row, int col) {
    current[row][col] = '.';
    for (int i = 0; i < coords.size(); i++) {
        pair<int, int> currentCoord = coords[i];
        int cx = row + currentCoord.first;
        int cy = col + currentCoord.second;
        while (cx >= 0 && cx < current.size() && cy >= 0 && cy < current.size()) {
            aux[cx][cy]--;
            cx += currentCoord.first;
            cy += currentCoord.second;
        }
    }
}

void dfs(vector<string>& current,
         vector<vector<int>>& aux,
         vector<vector<string>>& ans,
         int n,
         int placed,
         int row) {
    if (placed == n) {
        ans.push_back(current);
        return;
    }
    if (row >= n) return;
    for (int col = 0; col < n; col++) {
        if (aux[row][col] == 0) {
            placeQueen(current, aux, row, col);
            dfs(current, aux, ans, n, placed + 1, row + 1);
            deleteQueen(current, aux, row, col);
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<string> current(n, string(n, '.'));
    vector<vector<int>> aux(n, vector<int>(n, 0));
    vector<vector<string>> ans;
    dfs(current, aux, ans, n, 0, 0);
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 4;
    vector<vector<string>> solutions = solveNQueens(n);

    cout << "Found " << solutions.size() << " solutions for " << n << "-Queens:" << endl;

    for (int i = 0; i < solutions.size(); i++) {
        cout << "\nSolution " << (i + 1) << ":" << endl;
        for (int j = 0; j < solutions[i].size(); j++) {
            cout << solutions[i][j] << endl;
        }
    }

    return 0;
}
