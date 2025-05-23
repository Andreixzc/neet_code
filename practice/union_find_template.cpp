#include <bits/stdc++.h>
using namespace std;

// Implement Union Find data structure
class UnionFind {
private:
    // TODO: Add your member variables here
    // Typically parent array and rank array

public:
    // Initialize with n elements (0 to n-1)
    UnionFind(int n) {
        // TODO: Initialize parent array and rank array
    }
    
    // Find the representative (root) of the set containing x
    // with path compression
    int find(int x) {
        // TODO: Implement find with path compression
        return -1; // Replace with your implementation
    }
    
    // Union by rank: merge the sets containing x and y
    void unite(int x, int y) {
        // TODO: Implement union by rank
    }
    
    // Check if x and y are in the same set
    bool connected(int x, int y) {
        // TODO: Implement connected check
        return false; // Replace with your implementation
    }
};