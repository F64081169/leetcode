class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        if (mat.empty()) return mat;
        
        int rows = mat.size();
        int cols = mat[0].size();
        
        vector<vector<int>> distances(rows, vector<int>(cols, INT_MAX));
        queue<pair<int, int>> bfsQueue;
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (mat[i][j] == 0) {
                    distances[i][j] = 0;
                    bfsQueue.push({i, j});
                }
            }
        }
        
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!bfsQueue.empty()) {
            auto [x, y] = bfsQueue.front();
            bfsQueue.pop();
            
            for (const auto& dir : directions) {
                int newX = x + dir.first;
                int newY = y + dir.second;
                
                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols) {
                    if (distances[newX][newY] > distances[x][y] + 1) {
                        distances[newX][newY] = distances[x][y] + 1;
                        bfsQueue.push({newX, newY});
                    }
                }
            }
        }
        
        return distances;
    }
};
