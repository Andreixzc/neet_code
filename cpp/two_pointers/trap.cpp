#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
using namespace std;

int trap(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int leftMax = 0, rightMax = 0;
    int totalArea = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] >= leftMax) {
                leftMax = height[left];
            } else {
                totalArea += leftMax - height[left];
            }
            left++;
        } else {
            if (height[right] >= rightMax) {
                rightMax = height[right];
            } else {
                totalArea += rightMax - height[right];
            }
            right--;
        }
    }
    return totalArea;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> input = {4, 2, 3};
    cout << trap(input) << endl;  // Output should be 6
    return 0;
}
