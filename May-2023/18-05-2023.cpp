// C++ code
class Solution {
public:
    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int row, int col, int N, int M) {
        if (row < 0 || col < 0 || row >= N || col >= M || visited[row][col] || matrix[row][col] == 0)
            return;

        visited[row][col] = true; // Mark as visited

        dfs(matrix, visited, row - 1, col, N, M); // Up
        dfs(matrix, visited, row + 1, col, N, M); // Down
        dfs(matrix, visited, row, col - 1, N, M); // Left
        dfs(matrix, visited, row, col + 1, N, M); // Right
    }

    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        // Create boolean 2D visited matrix
        // to keep track of visited cells
        vector<vector<bool>> visited(N, vector<bool>(M, false));

        // Mark visited all lands
        // that are reachable from the edge
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                // Traverse corners
                if ((i * j == 0 || i == N - 1 || j == M - 1) && matrix[i][j] == 1 && !visited[i][j])
                    dfs(matrix, visited, i, j, N, M);
            }
        }

        // To store the number of closed islands
        int result = 0;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                // If the land is not visited
                // then there will be at least
                // one closed island
                if (!visited[i][j] && matrix[i][j] == 1) {
                    result++;

                    // Mark all lands associated
                    // with the island as visited
                    dfs(matrix, visited, i, j, N, M);
                }
            }
        }

        // Return the final count
        return result;
    }
};
