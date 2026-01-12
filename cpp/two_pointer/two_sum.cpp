#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0;
    int right = numbers.size() - 1;

    while (left < right) {
        int current = numbers[left] + numbers[right];
        if (current < target)
            left++;
        else if (current > target)
            right--;
        else
            return { left + 1, right + 1 };
    }

    return {};
}
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> input = { 1, 2, 3, 4 };
    vector<int> output = twoSum(input, 3);

    for (int element : output) cout << element << " ";

    return 0;
}
