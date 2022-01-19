#include "../includes.hpp"
using namespace std;

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        if (rows == 0)
            return matrix;
        int cols = matrix[0].size();

        vector<vector<int>> dist(rows, vector<int>(cols, INT32_MAX));
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == 0)
                {
                    dist[i][j] = 0;
                }
                else
                {
                    for (int k = 0; k < rows; k++)
                    {
                        for (int l = 0; l < cols; l++)
                        {
                            if (matrix[k][l] == 0)
                            {
                                int dist_01 = abs(k - i) + abs(l - j);
                                dist[i][j] = min(dist[i][j], abs(k - i) + abs(l - j));
                            }
                        }
                    }
                }
            }
        }
        
        return dist;
    }
};
