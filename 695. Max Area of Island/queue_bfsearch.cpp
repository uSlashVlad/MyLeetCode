#include "../includes.hpp"
using namespace std;

class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int result = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    queue<pair<int, int>> coordsQueue;
                    int islandArea = 0;
                    coordsQueue.push({i, j});

                    while (coordsQueue.size() > 0)
                    {
                        auto cell = coordsQueue.front();
                        coordsQueue.pop();

                        if (grid[cell.first][cell.second] != 1)
                            continue;
                        grid[cell.first][cell.second] = 2;
                        islandArea++;

                        if (cell.first != 0)
                            coordsQueue.push({cell.first - 1, cell.second});
                        if (cell.second != 0)
                            coordsQueue.push({cell.first, cell.second - 1});
                        if (cell.first != m - 1)
                            coordsQueue.push({cell.first + 1, cell.second});
                        if (cell.second != n - 1)
                            coordsQueue.push({cell.first, cell.second + 1});
                    }

                    result = max(result, islandArea);
                }
            }
        }

        return result;
    }
};