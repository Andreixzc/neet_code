#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl '\n'
vector<int> topKFrequent(vector<int>& nums, int k) {

    vector<int> ans;
    unordered_map<int,int> freqMap;
    for(int i = 0; i < nums.size(); i++){
        freqMap[nums[i]]++;

    }

    auto comparator = [&freqMap](int k1,int k2){
        return freqMap[k1] > freqMap[k2];
    };
    

    priority_queue<int, vector<int>, decltype(comparator)> heap(comparator);

    for(auto kv : freqMap){
        heap.push(kv.first);
        if(heap.size()> k) heap.pop();
    }
    for(int i = 0; i<k; i++){
        ans.push_back(heap.top());
        heap.pop();
    }
    return ans;


}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> input = { 4,1,-1,2,-1,2,3 };
    int k = 2;

    // Chamando a função e imprimindo o vetor
    vector<int> result = topKFrequent(input, k);

    // Imprimindo o resultado
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
