#include "../includes.hpp"
using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int level = triangle.size() - 2;
        while (level >= 0)
        {
            for (int i = 0; i < triangle[level].size(); i++)
                triangle[level][i] += min(triangle[level + 1][i],
                                          triangle[level + 1][i + 1]);
            level--;
        }

        return triangle[0][0];
    }
};
