#include "../includes.hpp"
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        set<int> s;
        for (int i = 0; i < nums.size(); i++)
            s.insert(nums[i]);

        nums.clear();
        nums.assign(s.begin(), s.end());

        return nums.size();
    }
};
