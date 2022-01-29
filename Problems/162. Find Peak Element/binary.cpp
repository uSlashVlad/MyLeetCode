#include "../includes.hpp"
using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;

        while (l < r)
        {
            int m1 = (l + r) / 2, m2 = m1 + 1;
            if (nums[m1] < nums[m2])
                l = m2;
            else
                r = m1;
        }

        return l;
    }
};
