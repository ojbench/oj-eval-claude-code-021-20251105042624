#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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

    // Improved strategy: Use a systematic approach to clear bricks
    // We'll use a pattern that alternates between different operations
    // to create a scanning motion across the playing field

    // Calculate total number of bricks
    int total_bricks = 4 * n * n;

    // Use a pattern that gradually increases horizontal velocity
    // to systematically clear bricks from different areas
    vector<char> operations;

    // Strategy: Use alternating operations to create a zig-zag pattern
    // This helps cover the entire playing field efficiently
    for (int i = 0; i < m && operations.size() < m; i++) {
        // Use different patterns based on the iteration
        if (i % 8 == 0) operations.push_back('C');  // No change
        else if (i % 8 == 1) operations.push_back('D');  // Right +1
        else if (i % 8 == 2) operations.push_back('C');  // No change
        else if (i % 8 == 3) operations.push_back('E');  // Right +2
        else if (i % 8 == 4) operations.push_back('C');  // No change
        else if (i % 8 == 5) operations.push_back('B');  // Left +1
        else if (i % 8 == 6) operations.push_back('C');  // No change
        else operations.push_back('A');  // Left +2
    }

    // Output all operations
    for (char op : operations) {
        cout << op << endl;
    }

    return 0;
}