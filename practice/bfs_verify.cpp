#include <bits/stdc++.h>
using namespace std;

// Include your BFS implementation
#include "bfs_template.cpp"

void test_bfs() {
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
    
    vector<int> expected1 = {0, 1, 2, 3, 4, 5, 6};
    vector<int> result1 = bfs(graph1, 0);
    
    assert(result1 == expected1 && "BFS traversal order is incorrect!");
    
    // Test case 2: Disconnected graph
    vector<vector<int>> graph2 = {
        {1, 2},     // Node 0 is connected to 1, 2
        {0},        // Node 1 is connected to 0
        {0},        // Node 2 is connected to 0
        {4},        // Node 3 is connected to 4
        {3}         // Node 4 is connected to 3
    };
    
    vector<int> expected2 = {0, 1, 2};
    vector<int> result2 = bfs(graph2, 0);
    
    assert(result2 == expected2 && "BFS traversal order is incorrect!");
    
    cout << "All BFS tests passed!" << endl;
}

int main() {
    test_bfs();
    return 0;
}