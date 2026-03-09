#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
      : val(0)
      , left(nullptr)
      , right(nullptr) {
    }
    TreeNode(int x)
      : val(x)
      , left(nullptr)
      , right(nullptr) {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x)
      , left(left)
      , right(right) {
    }
};

TreeNode* invertTree(TreeNode* root) {

    return nullptr;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
