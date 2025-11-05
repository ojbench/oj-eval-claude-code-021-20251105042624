#include <iostream>
#include <vector>
#include <string>
#include "game.h"

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

    // Simple strategy: always use operation C (no change) to let the ball
    // bounce naturally and hit bricks. This is a naive approach that should
    // work for simple cases but won't be optimal for larger cases.

    // For now, output a fixed number of operations
    // We need to estimate how many times the ball will hit the bottom
    // A rough estimate: the ball will hit bottom roughly n times
    int operations = min(m, 2 * n);

    for (int i = 0; i < operations; i++) {
        cout << "C" << endl;
    }

    return 0;
}