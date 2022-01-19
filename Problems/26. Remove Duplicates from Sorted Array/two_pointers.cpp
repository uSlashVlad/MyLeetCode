#include "../includes.hpp"
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int l = nums.size();

        if (l <= 1)
            return l;

        int j = 1;
        for (int i = 1; i < l; i++)
        {
            if (nums[i] != nums[j - 1])
            {
                nums[j] = nums[i];
                j++;
            }
        }

        return j;
    }
};
