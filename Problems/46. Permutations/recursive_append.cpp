#include "../includes.hpp"
using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        if (nums.size() == 1) // [2], [3]
            return {nums};

        vector<vector<int>> result;

        for (int i = 0; i < nums.size(); i++)
        {
            int deletedElement = nums[i];
            swap(nums[i], nums[nums.size() - 1]);
            nums.resize(nums.size() - 1);

            auto temp = permute(nums);
            nums.push_back(deletedElement);
            swap(nums[i], nums[nums.size() - 1]);

            for (auto combination : temp)
            {
                combination.push_back(nums[i]);
                result.push_back(combination);
            }
        }

        return result;
    }
};
