#include "../includes.hpp"
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> parentheses;

        for (auto ch : s)
        {
            switch (ch)
            {
            case '(':
            case '[':
            case '{':
                parentheses.push(ch);
                break;
            default:
                if (!parentheses.empty() && (parentheses.top() == ch - 1 || parentheses.top() == ch - 2))
                    parentheses.pop();
                else
                    parentheses.push(ch);
                break;
            }
        }

        return parentheses.empty();
    }
};
