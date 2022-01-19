#include "../includes.hpp"
using namespace std;

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        queue<pair<int, int>> coordsQueue;
        int requiredNum = image[sr][sc];
        if (requiredNum == newColor)
            return image;
            
        int m = image.size();
        int n = image[0].size();
        coordsQueue.push({sr, sc});

        while (coordsQueue.size() > 0)
        {
            auto cell = coordsQueue.front();
            coordsQueue.pop();

            if (image[cell.first][cell.second] != requiredNum)
                continue;
            image[cell.first][cell.second] = newColor;

            if (cell.first != 0)
                coordsQueue.push({cell.first - 1, cell.second});
            if (cell.second != 0)
                coordsQueue.push({cell.first, cell.second - 1});
            if (cell.first != m - 1)
                coordsQueue.push({cell.first + 1, cell.second});
            if (cell.second != n - 1)
                coordsQueue.push({cell.first, cell.second + 1});
        }

        return image;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> image{{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    s.floodFill(image, 1, 1, 2);
}
