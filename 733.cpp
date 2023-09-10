class Solution {
public:
    void recursion(vector<vector<int>>& image, int sr, int sc, int color, int ori){
        if (image[sr][sc] != color){
            image[sr][sc] = color;
            
            if (sr-1 >= 0 && image[sr-1][sc] != color && image[sr-1][sc] == ori){
                recursion(image, sr-1, sc, color, ori);
            }
            if (sr+1 < image.size() && image[sr+1][sc] != color && image[sr+1][sc] == ori){
                recursion(image, sr+1, sc, color, ori);
            }
            if (sc-1 >= 0 && image[sr][sc-1] != color && image[sr][sc-1] == ori){
                recursion(image, sr, sc-1, color, ori);
            }
            if (sc+1 < image[0].size() && image[sr][sc+1] != color && image[sr][sc+1] == ori){
                recursion(image, sr, sc+1, color, ori);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        recursion(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};