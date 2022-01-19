#include "../includes.hpp"
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> states(m, vector<int>(n, INT32_MIN));
        queue<pair<int, int>> coordsQueue;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    states[i][j] = -1;
                else if (grid[i][j] == 2)
                {
                    states[i][j] = 0;
                    coordsQueue.push({i, j});
                }
            }
        }

        int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!coordsQueue.empty())
        {
            pair<int, int> cell = coordsQueue.front();
            coordsQueue.pop();

            for (int i = 0; i < 4; i++)
            {
                int newY = cell.first + dir[i][0];
                int newX = cell.second + dir[i][1];
                if (newY >= 0 && newX >= 0 && newY < m && newX < n)
                {
                    if (states[newY][newX] == -1)
                    {
                        states[newY][newX] = states[cell.first][cell.second] + 1;
                        coordsQueue.push({newY, newX});
                    }
                }
            }
        }

        int result = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (states[i][j] == -1)
                    return -1;
                if (states[i][j] > result)
                    result = states[i][j];
            }
        }
        return result;
    }
};
