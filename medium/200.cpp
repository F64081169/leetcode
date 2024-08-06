class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        int cnt = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    dfs(grid, visited, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }

private:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == '0' || visited[i][j]) {
            return;
        }
        
        visited[i][j] = true;
        
        dfs(grid, visited, i + 1, j);
        dfs(grid, visited, i - 1, j);
        dfs(grid, visited, i, j + 1);
        dfs(grid, visited, i, j - 1);
    }
};
