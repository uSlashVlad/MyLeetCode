bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        for (int i = 1; i <= n; i += 2)
        {
            if (isBadVersion(i))
            {
                if (isBadVersion(i - 1))
                    return i - 1;
                else
                    return i;
            }
        }
        return n;
    }
};
