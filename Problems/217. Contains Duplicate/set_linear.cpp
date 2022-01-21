#include "../includes.hpp"
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        set<int> numsSet;

        for (int n : nums)
        {
            if (numsSet.count(n) == 1)
                return true;
            numsSet.insert(n);
        }

        return false;
    }
};
