#include "../includes.hpp"
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int count = nums.size();
        for (int i = 0; i < count; i++)
        {
            for (int j = i + 1; j < count; j++)
            {
                if (nums[i] + nums[j] == target)
                    return {i, j};
            }
        }

        return {};
    }
};
