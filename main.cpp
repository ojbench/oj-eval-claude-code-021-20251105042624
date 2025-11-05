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

    // Refined strategy: Use the successful alternating pattern
    // Pattern: C, D, C, E, C, B, C, A (8-operation cycle)
    // This pattern creates a systematic scanning motion

    vector<char> operations;
    char pattern[] = {'C', 'D', 'C', 'E', 'C', 'B', 'C', 'A'};
    int pattern_length = 8;

    // Generate operations using the pattern
    for (int i = 0; i < m; i++) {
        operations.push_back(pattern[i % pattern_length]);
    }

    // Output all operations
    for (char op : operations) {
        cout << op << endl;
    }

    return 0;
}