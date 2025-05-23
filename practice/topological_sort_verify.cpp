#include <bits/stdc++.h>
using namespace std;

// Include your topological sort implementation
#include "topological_sort_template.cpp"

void test_topological_sort() {
    // Test case 1: Simple DAG
    vector<vector<int>> graph1 = {
        {1, 2},      // Node 0 has edges to 1, 2
        {3},         // Node 1 has edge to 3
        {3},         // Node 2 has edge to 3
        {4, 5},      // Node 3 has edges to 4, 5
        {},          // Node 4 has no outgoing edges
        {}           // Node 5 has no outgoing edges
    };
    
    vector<int> result1 = topological_sort(graph1);
    
    // Check if all nodes are in the result
    assert(result1.size() == graph1.size() && "Not all nodes are in the result!");
    
    // Check if the topological order is valid
    vector<bool> visited(graph1.size(), false);
    for (int node : result1) {
        visited[node] = true;
        for (int neighbor : graph1[node]) {
            assert(find(result1.begin(), result1.end(), neighbor) > find(result1.begin(), result1.end(), node) && 
                   "Invalid topological order!");
        }
    }
    
    // Test case 2: Another DAG
    vector<vector<int>> graph2 = {
        {},          // Node 0 has no outgoing edges
        {0},         // Node 1 has edge to 0
        {0, 1},      // Node 2 has edges to 0, 1
        {1, 2}       // Node 3 has edges to 1, 2
    };
    
    vector<int> result2 = topological_sort(graph2);
    
    // Check if all nodes are in the result
    assert(result2.size() == graph2.size() && "Not all nodes are in the result!");
    
    // Check if the topological order is valid
    vector<bool> visited2(graph2.size(), false);
    for (int node : result2) {
        visited2[node] = true;
        for (int neighbor : graph2[node]) {
            assert(find(result2.begin(), result2.end(), neighbor) > find(result2.begin(), result2.end(), node) && 
                   "Invalid topological order!");
        }
    }
    
    cout << "All topological sort tests passed!" << endl;
}

int main() {
    test_topological_sort();
    return 0;
}