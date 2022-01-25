#include "../includes.hpp"
using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        return recursiveMinimum(triangle, 0, 0);
    }

    int recursiveMinimum(vector<vector<int>> &triangle, int level, int index)
    {
        if (level == triangle.size() - 1)
            return triangle[level][index];

        return min(recursiveMinimum(triangle, level + 1, index),
                   recursiveMinimum(triangle, level + 1, index + 1)) +
               triangle[level][index];
    }
};

int main()
{
    Solution s;
    vector<vector<int>> triangle{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    s.minimumTotal(triangle);
}
