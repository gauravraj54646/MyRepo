#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximalSquare(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    if (rows == 0) {
        return 0;
    }
    int cols = matrix[0].size();
    int maxSide = 0;
    vector<vector<int>> dp(rows,vector<int>(cols, 0));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i == 0 || j == 0) {
                dp[i][j] = matrix[i][j];
            } else if (matrix[i][j] == 1) {
                dp[i][j] = std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            }
            maxSide = max(maxSide, dp[i][j]);
        }
    }
    return maxSide * maxSide;
}

int main() {
    vector<vector<int>> matrix = {{1, 0, 1, 0, 0},
                                           {1, 0, 1, 1, 1},
                                           {1, 1, 1, 1, 1},
                                           {1, 0, 0, 1, 0}};

    int result = maximalSquare(matrix);
    cout << "Maximum square containing only 1s has area: " << result << std::endl;

    return 0;
}
