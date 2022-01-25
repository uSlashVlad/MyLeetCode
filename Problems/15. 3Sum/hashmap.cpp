#include "../includes.hpp"
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        if (nums.size() < 3)
            return {};

        sort(nums.begin(), nums.end());
        map<int, int> numsMap;

        for (int i = 0; i < nums.size(); i++)
            numsMap[nums[i]] = i;

        vector<vector<int>> result;

        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (nums[i] > 0)
                break;

            for (int j = i + 1; j < nums.size() - 1; j++)
            {
                int estimated = -(nums[i] + nums[j]);
                if (numsMap.count(estimated) > 0 && numsMap[estimated] > j)
                    result.push_back({nums[i], nums[j], estimated});

                j = numsMap[nums[j]];
            }

            i = numsMap[nums[i]];
        }

        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums{-1, 0, 1, 2, -1, -4};
    s.threeSum(nums);
}
