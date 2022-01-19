#include "../includes.hpp"
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int length = nums.size();
        vector<int> normal(length);
        int normalCount = 0;

        for (int n : nums)
        {
            if (n != 0)
            {
                normal[normalCount] = n;
                normalCount++;
            }
        }

        nums = normal;
    }
};
