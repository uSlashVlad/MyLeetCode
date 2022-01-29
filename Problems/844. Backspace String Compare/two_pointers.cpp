#include "../includes.hpp"
using namespace std;

class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        int p1 = s.length() - 1, p2 = t.length() - 1, skip;

        while (true)
        {
            skip = 0;
            while (p1 >= 0 && (skip > 0 || s[p1] == '#'))
            {
                skip += s[p1] == '#' ? 1 : -1;
                p1--;
            }

            skip = 0;
            while (p2 >= 0 && (skip > 0 || t[p2] == '#'))
            {
                skip += t[p2] == '#' ? 1 : -1;
                p2--;
            }

            if (p1 >= 0 && p2 >= 0 && s[p1] == t[p2])
            {
                p1--;
                p2--;
            }
            else
            {
                break;
            }
        }
        
        return p1 == -1 && p2 == -1;
    }
};

int main()
{
    Solution().backspaceCompare("xywrrmp", "xywrrmu#p");
}
