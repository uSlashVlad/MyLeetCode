#include "../includes.hpp"
using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int count = nums.size();
        vector<int> res(count);

        int k = count - 1;
        int left = 0;
        int right = k;

        while (k >= 0)
        {
            int lv = nums[left];
            int rv = nums[right];
            if (abs(lv) >= abs(rv))
            {
                res[k] = lv * lv;
                left++;
            }
            else
            {
                res[k] = rv * rv;
                right--;
            }
            k--;
        }

        return res;
    }
};
