#include "../includes.hpp"
using namespace std;

// This solution goes from 0s to all nearest 1s, calculates distance and
// stores it in the result matrix

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> distances(m, vector<int>(n, INT32_MAX));
        queue<pair<int, int>> coordsQueue;
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    distances[i][j] = 0;
                    coordsQueue.push({i, j}); // Put all 0s in the queue.
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
                    if (distances[newY][newX] > distances[cell.first][cell.second] + 1)
                    {
                        distances[newY][newX] = distances[cell.first][cell.second] + 1;
                        coordsQueue.push({newY, newX});
                    }
                }
            }
        }
        return distances;
    }
};
