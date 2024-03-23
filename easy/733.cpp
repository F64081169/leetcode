class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(color==image[sr][sc]) return image;
        DFS(image,sr,sc,image[sr][sc],color);
        return image;
    }
private:
    void DFS(vector<vector<int>>& image,int x,int y,int oldColor,int newColor){
        if(x<0 || y<0 || x>=image.size()|| y>=image[0].size()) return;
        if(image[x][y] != oldColor) return;

        image[x][y] = newColor;
        DFS(image,x+1,y,oldColor,newColor);
        DFS(image,x,y+1,oldColor,newColor);
        DFS(image,x-1,y,oldColor,newColor);
        DFS(image,x,y-1,oldColor,newColor);
    }
};
