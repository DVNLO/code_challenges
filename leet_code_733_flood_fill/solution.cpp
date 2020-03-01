class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, 
                                  int sr, 
                                  int sc, 
                                  int newColor) 
    {
        int const MIN_ROW{ 0 };
        int const MIN_COL{ 0 };
        int const MAX_ROW{ static_cast<int>(image.size()) };
        int const MAX_COL{ static_cast<int>(image[0].size()) };
        int const start_color{ image[sr][sc] };
        if(start_color == newColor)
            return image;
        queue<pair<int, int>> points;
        pair<int, int> p{ sr, sc };
        points.push(p);
        while(!points.empty())
        {
            p = points.front();
            points.pop();
            image[p.first][p.second] = newColor;
            if(p.first - 1 >= MIN_ROW
                && image[p.first - 1][p.second] == start_color) // up
                points.push(make_pair(p.first - 1, p.second));
            if(p.first + 1 < MAX_ROW
                && image[p.first + 1][p.second] == start_color) // down
                points.push(make_pair(p.first + 1, p.second));
            if(p.second - 1 >= MIN_COL
                && image[p.first][p.second - 1] == start_color) // left
                points.push(make_pair(p.first, p.second - 1));
            if(p.second + 1 < MAX_COL
                && image[p.first][p.second + 1] == start_color) // right
                points.push(make_pair(p.first, p.second + 1));
        }
        return image;
    }
};
