#include "../includes.hpp"
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();    // Rows count
        int n = matrix[0].size(); // Columns count

        int l = 0, r = m * n - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            int row = mid / n, col = mid % n;
            if (target > matrix[row][col])
                l = mid + 1;
            else if (target < matrix[row][col])
                r = mid - 1;
            else
                return true;
        }

        return false;
    }
};

/**
 * [[1,3,5,7],[10,11,16,20],[23,30,34,60]]
 * 
 * m = 3, n = 4
 *  1  3  5  7
 * 10 11 16 20
 * 23 30 34 60
 * 
 *  0  1  2  3
 *  4  5  6  7
 *  8  9 10 11
 * 
 * row = mid / n
 * col = mid % n
 */