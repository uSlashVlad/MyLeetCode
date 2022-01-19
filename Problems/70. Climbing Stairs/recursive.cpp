class Solution
{
public:
    int climbStairs(int n)
    {
        // base cases
        if (n <= 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;

        int oneStepBefore = 2;
        int twoStepsBefore = 1;
        int allWays = 0;

        for (int i = 2; i < n; i++)
        {
            allWays = oneStepBefore + twoStepsBefore;
            twoStepsBefore = oneStepBefore;
            oneStepBefore = allWays;
        }
        return allWays;
    }
};
