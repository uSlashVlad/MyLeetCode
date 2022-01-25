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
        sums[1] = nums[1];

        int result = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i++)
        {
            int m = -1;
            for (int j = 0; j < i - 1; j++)
                if (sums[j] > m)
                    m = sums[j];

            sums[i] = nums[i] + m;
            if (sums[i] > result)
                result = sums[i];
        }

        return result;
    }
};
