bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        long int low = 1;
        long int high = n;
        while (low <= high)
        {
            long int mid = (low + high) / 2;
            if (isBadVersion(mid))
            {
                if (isBadVersion(mid - 1))
                    high = mid - 1;
                else
                    return mid;
            }
            else
            {
                if (isBadVersion(mid + 1))
                    return mid + 1;
                else
                    low = mid + 2;
            }
        }
        return 1;
    }
};
