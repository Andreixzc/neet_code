#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
#include <algorithm>
#include <cassert>
#include <cmath>

int carFleet(int target, vector<int>& position, vector<int>& speed) {

    vector<pair<int, int>> cars(position.size());
    stack<pair<int, int>> st;
    for (int i = 0; i < position.size(); i++) cars[i] = { position[i], speed[i] };
    sort(cars.begin(), cars.end());

    for (int i = cars.size() - 1; i >= 0; i--) {
        if (st.empty()) {
            st.push(cars[i]);
            continue;
        }
        double currentArrivalTime = (double)(target - cars[i].first) / cars[i].second;
        double topArrivalTime = (double)(target - st.top().first) / st.top().second;
        if (currentArrivalTime <= topArrivalTime) continue;
        st.push(cars[i]);
    }

    return st.size();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> positions = { 6, 8 };
    vector<int> speed = { 3, 2 };
    int target = 10;
    cout << carFleet(target, positions, speed);
    return 0;
}
