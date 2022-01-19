#include "../includes.hpp"
using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int length = nums.size();
        if (length < 2)
            return;

        k = k % length;
        reverse(nums, 0, length - k - 1);
        reverse(nums, length - k, length - 1);
        reverse(nums, 0, length - 1);
    }

    void reverse(vector<int> &nums, int left, int right)
    {
        while (left < right)
        {
            int tmp = nums[left];
            nums[left] = nums[right];
            nums[right] = tmp;

            left++;
            right--;
        }
    }
};
