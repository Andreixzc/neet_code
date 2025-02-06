#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'

int carFleet(int target, vector<int>& position, vector<int>& speed) {
    int n = position.size();
    if (n == 0) return 0;
    vector<pair<int, double>> cars;
    for (int i = 0; i < n; i++) cars.push_back({position[i], speed[i]});
    sort(cars.rbegin(), cars.rend());
    for (auto element : cars) cout << element.first << endl;
    vector<double> times(n);
    for (int i = 0; i < n; i++) times[i] = (double)(target - cars[i].first) / cars[i].second;
    int fleets = 1;
    double curr_time = times[0];
    for (int i = 1; i < n; i++) {
        if (times[i] > curr_time) {
            fleets++;
            curr_time = times[i];
        }
    }

    return fleets;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int target = 12;
    vector<int> position = {10, 8, 0, 5, 3};
    vector<int> speed = {2, 4, 1, 1, 3};

    cout << carFleet(target, position, speed) << endl;

    return 0;
}
