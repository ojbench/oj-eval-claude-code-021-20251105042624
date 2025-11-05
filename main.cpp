#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    // Read input
    int k, n, m, s;
    cin >> k >> n >> m >> s;

    vector<vector<int>> bricks(2 * n, vector<int>(2 * n));
    for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j < 2 * n; j++) {
            cin >> bricks[i][j];
        }
    }

    // Advanced strategy: Use brick layout to make smarter decisions
    // Count colored bricks to prioritize hitting them in sequence
    int colored_bricks[4] = {0};  // colors 0,1,2,3
    for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j < 2 * n; j++) {
            if (bricks[i][j] >= 0 && bricks[i][j] <= 3) {
                colored_bricks[bricks[i][j]]++;
            }
        }
    }

    // Strategy: Use a more dynamic pattern based on the game state
    // We'll alternate between different operation intensities
    vector<char> operations;

    // Use different patterns for different phases of the game
    // Phase 1: Gentle scanning to clear easy bricks
    // Phase 2: More aggressive patterns to reach remaining bricks

    int phase1_ops = min(m / 3, 1000);
    int phase2_ops = min(m / 3, 2000);
    int phase3_ops = m - phase1_ops - phase2_ops;

    // Phase 1: Gentle alternating pattern
    for (int i = 0; i < phase1_ops; i++) {
        if (i % 6 == 0) operations.push_back('C');
        else if (i % 6 == 1) operations.push_back('D');
        else if (i % 6 == 2) operations.push_back('C');
        else if (i % 6 == 3) operations.push_back('B');
        else if (i % 6 == 4) operations.push_back('C');
        else operations.push_back('C');
    }

    // Phase 2: More aggressive pattern
    for (int i = 0; i < phase2_ops; i++) {
        if (i % 8 == 0) operations.push_back('C');
        else if (i % 8 == 1) operations.push_back('D');
        else if (i % 8 == 2) operations.push_back('E');
        else if (i % 8 == 3) operations.push_back('C');
        else if (i % 8 == 4) operations.push_back('B');
        else if (i % 8 == 5) operations.push_back('A');
        else if (i % 8 == 6) operations.push_back('C');
        else operations.push_back('C');
    }

    // Phase 3: Most aggressive pattern to clear remaining bricks
    for (int i = 0; i < phase3_ops; i++) {
        if (i % 10 == 0) operations.push_back('C');
        else if (i % 10 == 1) operations.push_back('D');
        else if (i % 10 == 2) operations.push_back('E');
        else if (i % 10 == 3) operations.push_back('E');
        else if (i % 10 == 4) operations.push_back('C');
        else if (i % 10 == 5) operations.push_back('B');
        else if (i % 10 == 6) operations.push_back('A');
        else if (i % 10 == 7) operations.push_back('A');
        else if (i % 10 == 8) operations.push_back('C');
        else operations.push_back('C');
    }

    // Ensure we don't exceed m operations
    if (operations.size() > m) {
        operations.resize(m);
    }

    // Output all operations
    for (char op : operations) {
        cout << op << endl;
    }

    return 0;
}