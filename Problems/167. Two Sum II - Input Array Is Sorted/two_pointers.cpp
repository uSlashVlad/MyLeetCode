#include "../includes.hpp"
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high)
        {
            if (nums[low] + nums[high] > target)
                high--;
            else if (nums[low] + nums[high] < target)
                low++;
            else
                return {low + 1, high + 1};
        }

        return {};
    }
};
