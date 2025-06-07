#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
using namespace std;

// Global counters for operations
int forloop_calls = 0;
int forloop_comparisons = 0;
int binary_calls = 0;
int binary_comparisons = 0;

class ForLoopSolution {
  public:
    vector<vector<int>> res;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        res.clear();
        forloop_calls = 0;
        forloop_comparisons = 0;
        sort(candidates.begin(), candidates.end());
        dfs(0, {}, 0, candidates, target);
        return res;
    }

  private:
    void dfs(int idx, vector<int> path, int cur, vector<int>& candidates, int target) {
        forloop_calls++;

        if (cur == target) {
            res.push_back(path);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            forloop_comparisons++; // for loop condition check

            if (i > idx && candidates[i] == candidates[i - 1]) {
                forloop_comparisons++; // duplicate check
                continue;
            }
            forloop_comparisons++; // duplicate check (even when false)

            if (cur + candidates[i] > target) {
                forloop_comparisons++; // target check
                break;
            }
            forloop_comparisons++; // target check (even when false)

            path.push_back(candidates[i]);
            dfs(i + 1, path, cur + candidates[i], candidates, target);
            path.pop_back();
        }
    }
};

class BinaryChoiceSolution {
  public:
    vector<vector<int>> res;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        res.clear();
        binary_calls = 0;
        binary_comparisons = 0;
        sort(candidates.begin(), candidates.end());
        dfs(0, {}, 0, candidates, target);
        return res;
    }

  private:
    void dfs(int idx, vector<int> path, int cur, vector<int>& candidates, int target) {
        binary_calls++;

        if (cur == target) {
            res.push_back(path);
            return;
        }

        if (idx >= candidates.size() || cur > target) {
            binary_comparisons++; // boundary/target check
            return;
        }
        binary_comparisons++; // boundary/target check (even when false)

        // Skip duplicates - find next different element
        int next_different = idx;
        while (next_different < candidates.size() &&
               candidates[next_different] == candidates[idx]) {
            binary_comparisons++; // duplicate search
            next_different++;
        }

        // Choice 1: Skip all instances of current element
        if (next_different < candidates.size()) {
            binary_comparisons++; // boundary check
            dfs(next_different, path, cur, candidates, target);
        }
        binary_comparisons++; // boundary check (even when false)

        // Choice 2: Include current element (and potentially more of same value)
        for (int count = 1; count <= next_different - idx; count++) {
            if (cur + candidates[idx] * count > target) {
                binary_comparisons++; // target check
                break;
            }
            binary_comparisons++; // target check (even when false)

            // Add 'count' instances of current element
            for (int i = 0; i < count; i++) {
                path.push_back(candidates[idx]);
            }

            dfs(next_different, path, cur + candidates[idx] * count, candidates, target);

            // Remove 'count' instances
            for (int i = 0; i < count; i++) {
                path.pop_back();
            }
        }
    }
};

void benchmark() {
    vector<int> test_cases[][2] = { { { 10, 1, 2, 7, 6, 1, 5 }, { 8 } },
                                    { { 2, 5, 2, 1, 2 }, { 5 } },
                                    { { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, { 5 } },
                                    { { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, { 15 } },
                                    { { 2, 2, 2, 2, 2, 2, 2 }, { 8 } } };

    cout << "=== BENCHMARK RESULTS ===" << endl;
    cout << "Format: [Input] -> Target" << endl;
    cout << "Method | Calls | Comparisons | Solutions | Time(ms)" << endl;
    cout << "-------|-------|-------------|-----------|----------" << endl;

    for (int t = 0; t < 5; t++) {
        vector<int> candidates = test_cases[t][0];
        int target = test_cases[t][1][0];

        cout << "\nTest " << (t + 1) << ": [";
        for (int i = 0; i < candidates.size(); i++) {
            cout << candidates[i];
            if (i < candidates.size() - 1) cout << ",";
        }
        cout << "] -> " << target << endl;

        // Test For-Loop approach
        ForLoopSolution forloop;
        auto start = chrono::high_resolution_clock::now();
        auto result1 = forloop.combinationSum2(candidates, target);
        auto end = chrono::high_resolution_clock::now();
        auto duration1 = chrono::duration_cast<chrono::microseconds>(end - start);

        cout << "ForLoop| " << forloop_calls << "     | " << forloop_comparisons << "           | "
             << result1.size() << "         | " << duration1.count() / 1000.0 << endl;

        // Test Binary Choice approach
        BinaryChoiceSolution binary;
        start = chrono::high_resolution_clock::now();
        auto result2 = binary.combinationSum2(candidates, target);
        end = chrono::high_resolution_clock::now();
        auto duration2 = chrono::duration_cast<chrono::microseconds>(end - start);

        cout << "Binary | " << binary_calls << "     | " << binary_comparisons << "           | "
             << result2.size() << "         | " << duration2.count() / 1000.0 << endl;

        // Verify results are the same
        sort(result1.begin(), result1.end());
        sort(result2.begin(), result2.end());
        for (auto& r : result1) sort(r.begin(), r.end());
        for (auto& r : result2) sort(r.begin(), r.end());

        if (result1 != result2) {
            cout << "ERROR: Results don't match!" << endl;
        }
    }
}

int main() {
    benchmark();
    return 0;
}
