#include "../includes.hpp"
using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int path = 0;
        for (auto level : triangle)
        {
            int m = INT32_MAX;
            for (int num : level)
                if (m > abs(num))
                    m = num;
            path += m;
        }

        return path;
    }
};
