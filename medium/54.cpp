class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) return res; 
        int l = 0, r = matrix[0].size();
        int t = 0, b = matrix.size();

        while (l < r && t < b) {
            for (int j = l; j < r; j++) {
                res.push_back(matrix[t][j]);
            }
            t++; 

            for (int i = t; i < b; i++) {
                res.push_back(matrix[i][r - 1]);
            }
            r--; 

            if (t < b) {
                for (int j = r - 1; j >= l; j--) {
                    res.push_back(matrix[b - 1][j]);
                }
                b--; 
            }

            if (l < r) {
                for (int i = b - 1; i >= t; i--) {
                    res.push_back(matrix[i][l]);
                }
                l++; 
            }
        }

        return res;
    }
};
