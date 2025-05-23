#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> map;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    for (int i = 0; i < nums.size(); i++) map[nums[i]]++;
    for (auto pair : map) {
        heap.push({ pair.second, pair.first });
        if (heap.size() > k) heap.pop();
    }

    vector<int> ans;
    while (!heap.empty()) {
        auto entry = heap.top();
        ans.push_back(entry.second);
        heap.pop();
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
