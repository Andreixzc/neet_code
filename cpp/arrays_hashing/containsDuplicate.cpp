#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
    bool containsDuplicate(vector<int>& nums) {
    set<int> set;
    for(int i = 0; i < nums.size(); i++){
     if(set.contains(nums[i])) return true;
     else set.insert(nums[i]);   
    }
    return false;
    }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    return 0;
}

