#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
int maxArea(vector<int>& heights){
    int j = heights.size()-1;
    int i = 0;
    int overallMax = 0;
    while (i < j ){
        int currentArea = min(heights[i], heights[j]) * (j-i);
        overallMax = max(currentArea,overallMax);
        if(heights[i] < heights[j]) i++;
        else if(heights[i] > heights[j]) j--;
        else {
            i++;
            j--;
        }
    }
    return overallMax;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> input = {2,2,2};
    cout << maxArea(input) <<endl;
    return 0;
}

