#include "../includes.hpp"
using namespace std;

class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        if (k == 0)
            return {{}};

        vector<vector<int>> result;

        for (int i = n; i >= k; i--)
        {
            auto tempCombinations = combine(i - 1, k - 1);
            for (auto combination : tempCombinations)
            {
                combination.push_back(i);
                result.push_back(combination);
            }
        }

        return result;
    }
};

int main()
{
    Solution().combine(4, 2);
}

// n, k, maxK
// 4, 2, 2
// maxK-k = 0
// 3, 1, 2
// maxK-k = 1
// 2, 0, 2
// maxk-k = 2


// COMBINE(4, 3):
// result = []
//   for i in range(n-1, n-k):
//     tmp = combine(i, k-1)
//     result.append([i, ...tmp])

// [[4,3,2],[4,3,1],[4,2,1]]
// [[3,2],[3,1]]
// [[2]]
// [[1]]
// [[2,1]]

// 4 _ _
//   3 _
//     2
//     1
//   2 _
//     1
