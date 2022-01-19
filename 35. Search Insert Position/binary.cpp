#include "../includes.hpp"
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int guess = nums[mid];
            if (guess == target)
                return mid;
            else if (target < guess)
                high = mid - 1;
            else if (target > guess)
                low = mid + 1;
        }
        return (low == high) ? low - 1 : low;
    }
};
