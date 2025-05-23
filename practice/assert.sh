#!/bin/bash

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Create a build directory for compiled tests
mkdir -p build

# Array of all algorithms to test
algorithms=(
    "bfs"
    "dfs"
    "binary_search"
    "dijkstra"
    "fibonacci"
    "sliding_window"
    "topological_sort"
    "trie"
    "two_pointers"
    "union_find"
)

# Counter for successful tests
success_count=0
total_count=${#algorithms[@]}

# Function to run a test for a specific algorithm
run_test() {
    algorithm=$1
    echo -e "${BLUE}Testing ${algorithm}...${NC}"
    
    # Compile the verification file
    g++ -std=c++14 "${algorithm}_verify.cpp" -o "build/${algorithm}_test"
    
    # Check if compilation was successful
    if [ $? -eq 0 ]; then
        echo "Compilation successful."
        
        # Run the test
        "./build/${algorithm}_test"
        
        # Check if the test ran successfully
        if [ $? -eq 0 ]; then
            echo -e "${GREEN}✓ ${algorithm} tests passed!${NC}"
            return 0
        else
            echo -e "${RED}✗ ${algorithm} tests failed.${NC}"
            return 1
        fi
    else
        echo -e "${RED}✗ Compilation of ${algorithm} failed.${NC}"
        return 1
    fi
}

# Main testing loop
echo "=== Starting Algorithm Testing Suite ==="
echo "Testing ${total_count} algorithms..."
echo

for algo in "${algorithms[@]}"; do
    run_test "$algo"
    if [ $? -eq 0 ]; then
        ((success_count++))
    fi
    echo
done

# Print summary
echo "=== Testing Complete ==="
echo -e "${BLUE}Results: ${success_count}/${total_count} tests passed${NC}"

if [ $success_count -eq $total_count ]; then
    echo -e "${GREEN}All tests passed! Great job!${NC}"
else
    echo -e "${RED}Some tests failed. Check the output above for details.${NC}"
fi