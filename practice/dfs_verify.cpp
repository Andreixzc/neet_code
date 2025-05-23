#include <bits/stdc++.h>
using namespace std;

// Include your DFS implementation
#include "dfs_template.cpp"

void test_dfs() {
    // Test case 1: Simple graph
    vector<vector<int>> graph1 = {
        {1, 2},     // Node 0 is connected to 1, 2
        {0, 3, 4},  // Node 1 is connected to 0, 3, 4
        {0, 5, 6},  // Node 2 is connected to 0, 5, 6
        {1},        // Node 3 is connected to 1
        {1},        // Node 4 is connected to 1
        {2},        // Node 5 is connected to 2
        {2}         // Node 6 is connected to 2
    };
    
    vector<int> result1 = dfs(graph1, 0);
    
    // Check if all nodes are visited exactly once
    vector<bool> visited(graph1.size(), false);
    for (int node : result1) {
        assert(!visited[node] && "Node visited multiple times!");
        visited[node] = true;
    }
    for (bool v : visited) {
        assert(v && "Not all nodes were visited!");
    }
    
    // Check DFS property: For each node in the result, the next node must be a neighbor
    for (size_t i = 0; i < result1.size() - 1; i++) {
        int current = result1[i];
        int next = result1[i + 1];
        
        // Check if next is either a neighbor of current or a backtrack
        bool is_valid = false;
        for (int neighbor : graph1[current]) {
            if (neighbor == next) {
                is_valid = true;
                break;
            }
        }
        
        // If not a neighbor, check if it's a valid backtrack by checking previous nodes
        if (!is_valid) {
            bool is_backtrack = false;
            for (size_t j = 0; j < i; j++) {
                int prev_node = result1[j];
                for (int neighbor : graph1[prev_node]) {
                    if (neighbor == next) {
                        is_backtrack = true;
                        break;
                    }
                }
                if (is_backtrack) break;
            }
            assert(is_backtrack && "Invalid DFS traversal!");
        }
    }
    
    cout << "All DFS tests passed!" << endl;
}

int main() {
    test_dfs();
    return 0;
}