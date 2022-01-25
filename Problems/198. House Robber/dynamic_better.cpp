#include "../includes.hpp"
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];

        vector<int> sums(nums.size(), 0);
        sums[0] = nums[0];
        sums[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i++)
        {
            sums[i] = max(sums[i - 1], sums[i - 2] + nums[i]);
        }

        return sums[sums.size() - 1];
    }
};
