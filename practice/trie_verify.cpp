#include <bits/stdc++.h>
using namespace std;

// Include your Trie implementation
#include "trie_template.cpp"

void test_trie() {
    Trie trie;
    
    // Test case 1: Insert and search
    trie.insert("apple");
    assert(trie.search("apple") && "Word should be found after insertion!");
    assert(!trie.search("app") && "Prefix should not be a complete word!");
    
    // Test case 2: Prefix search
    assert(trie.startsWith("app") && "Prefix should be found!");
    assert(!trie.startsWith("ban") && "Non-existent prefix should not be found!");
    
    // Test case 3: More insertions and searches
    trie.insert("app");
    trie.insert("banana");
    trie.insert("application");
    
    assert(trie.search("app") && "Word should be found after insertion!");
    assert(trie.search("banana") && "Word should be found after insertion!");
    assert(trie.search("application") && "Word should be found after insertion!");
    assert(!trie.search("appl") && "Non-existent word should not be found!");
    assert(trie.startsWith("appl") && "Prefix should be found!");
    
    // Test case 4: Empty string
    assert(!trie.search("") && "Empty string should not be found initially!");
    trie.insert("");
    assert(trie.search("") && "Empty string should be found after insertion!");
    
    cout << "All Trie tests passed!" << endl;
}

int main() {
    test_trie();
    return 0;
}