#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> ans;
    int i = 0;
    int j = numbers.size()-1;
    while(i < j){
        if(numbers[i]+numbers[j] == target){
            ans.push_back(i+1);
            ans.push_back(j+1);
            return ans;
        }
        if(numbers[i]+ numbers[j] > target){
            j--;
            continue;
        }
        else i++;
    }
    return ans;
}
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    return 0;
}
