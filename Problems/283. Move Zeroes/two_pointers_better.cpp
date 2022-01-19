#include "../includes.hpp"
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int length = nums.size();
        if (length < 2)
            return;

        int j = 0;
        for (int i = 1; i < length; i++)
        {
            if (j < i && nums[i] != 0)
            {
                if (nums[j] == 0)
                {
                    nums[j] = nums[i];
                    nums[i] = 0;
                }
                j++;
            }
            else if (nums[j] != 0)
            {
                j++;
            }
        }
    }
};
