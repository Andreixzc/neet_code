#include <bits/stdc++.h>
using namespace std;

// Include your union find implementation
#include "union_find_template.cpp"

void test_union_find() {
    // Test case 1: Basic operations
    UnionFind uf1(5);
    
    // Initially, all elements should be in different sets
    for (int i = 0; i < 4; i++) {
        assert(!uf1.connected(i, i + 1) && "Elements should initially be disconnected!");
    }
    
    // Unite some elements
    uf1.unite(0, 1);
    uf1.unite(2, 3);
    
    // Check connections
    assert(uf1.connected(0, 1) && "Elements should be connected after union!");
    assert(uf1.connected(2, 3) && "Elements should be connected after union!");
    assert(!uf1.connected(0, 2) && "Disconnected elements should remain disconnected!");
    assert(!uf1.connected(1, 4) && "Disconnected elements should remain disconnected!");
    
    // Unite more elements
    uf1.unite(1, 2);
    
    // Check connections
    assert(uf1.connected(0, 3) && "Elements should be connected after union!");
    assert(!uf1.connected(0, 4) && "Disconnected elements should remain disconnected!");
    
    // Test case 2: Path compression and union by rank
    UnionFind uf2(10);
    
    // Create a specific structure to test path compression and union by rank
    uf2.unite(0, 1);
    uf2.unite(2, 3);
    uf2.unite(4, 5);
    uf2.unite(6, 7);
    uf2.unite(8, 9);
    
    uf2.unite(1, 3);
    uf2.unite(5, 7);
    
    uf2.unite(3, 7);
    uf2.unite(7, 9);
    
    // All elements should now be in the same set
    for (int i = 0; i < 9; i++) {
        assert(uf2.connected(i, i + 1) && "All elements should be connected!");
    }
    
    cout << "All Union Find tests passed!" << endl;
}

int main() {
    test_union_find();
    return 0;
}