#include "../includes.hpp"
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int l = 0,
            r = nums.size() - 1,
            m = r / 2;

        while (l <= r)
        {
            if (target > nums[m])
                l = m + 1;
            else if (target < nums[m])
                r = m - 1;
            else
                break;

            m = (l + r) / 2;
        }

        if (l > r)
            return {-1, -1};

        l = r = m;
        while (l >= 0 && nums[l] == target)
            l--;
        while (r < nums.size() && nums[r] == target)
            r++;
        
        return {l + 1, r - 1};
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1};
    s.searchRange(nums, 0);
}

/**
 *  5  7  7  8  8 10
 * ^     *        ^  (0+5)/2 = 2
 *          ^  *  ^  (3+5)/2 = 4
 *
 */
