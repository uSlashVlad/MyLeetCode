#include "../includes.hpp"
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int ind1 = lowerBound(nums, target);
        int ind2 = lowerBound(nums, target + 1) - 1;
        if (ind1 < nums.size() && nums[ind1] == target)
            return {ind1, ind2};
        else
            return {-1, -1};
    }

    int lowerBound(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int m = (r - l) / 2 + l;
            if (nums[m] < target)
                l = m + 1;
            else
                r = m - 1;
        }
        return l;
    }
};
