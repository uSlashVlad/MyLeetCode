#include "../includes.hpp"
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> numMap;

        int count = nums.size();
        for (int i = 0; i < count; i++)
        {
            auto item = numMap.find(target - nums[i]);

            if (item != numMap.end())
                return {i, item->second};

            numMap[nums[i]] = i;
        }

        return {};
    }
};
