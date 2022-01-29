#include "../includes.hpp"
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;
        int result = nums[0];

        while (l <= r)
        {
            if (nums[l] < nums[r])
            {
                result = min(result, nums[l]);
                break;
            }
            int mid = (l + r) / 2;
            result = min(result, nums[mid]);

            if (nums[mid] >= nums[l])
                l = mid + 1;
            else
                r = mid - 1;
        }

        return result;
    }
};
