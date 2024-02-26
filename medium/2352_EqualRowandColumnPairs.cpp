class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int cnt=0;
        
        for(int i = 0;i<grid.size();i++){
            for(int k = 0;k<grid.size();k++){
                bool flag = false;
                for(int j = 0;j<grid.size();j++){
                    if(grid[i][j] != grid[j][k]){
                        flag = true;
                        break;
                    }
                }
                if(!flag) cnt++;
            }
        }
        return cnt;
        /*
        11 1
        1  11
        */
    }
};
