class Solution {
public:
    void fill(int i,int j,int oldColor,int newColor,vector<vector<int>>&image ) {               

               if(i < 0 || i >= image.size() || j < 0 || j >= image[0].size() || image[i][j] != oldColor) return;
               image[i][j] = newColor;
               fill(i, j+1, oldColor, newColor, image);  
               fill(i, j-1, oldColor, newColor, image);
               fill(i+1, j, oldColor, newColor, image);
               fill(i-1, j, oldColor, newColor, image);
    } 
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
                int oldColor = image[sr][sc];

                if(oldColor != newColor) {
                    fill(sr, sc, oldColor, newColor, image);
                } 

                return image;
    }
};
