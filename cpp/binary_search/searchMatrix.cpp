#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    vector<int> possibleRow;
    bool notFound = true;
    for (int i = 0; i < matrix.size(); i++) {
        int first = matrix[i][0];
        int last = matrix[i][matrix.size()];
        if (target >= first && target <= last) {
            for (int j = 0; j < matrix[i].size(); j++) {
                possibleRow.push_back(matrix[i][j]);
            }
            notFound = false;
            break;
        }
    }
    if (notFound) return false;
    int left = 0;
    int right = possibleRow.size() - 1;

    while (left <= right) {
        int mid = (right + left) / 2;
        if (possibleRow[mid] == target)
            return true;
        else if (possibleRow[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<int>> matriz = { { 1, 2, 4, 8 }, { 10, 11, 12, 13 }, { 14, 20, 30, 40 } };
    cout << searchMatrix(matriz, 12) << endl;

    return 0;
}
