#include "../includes.hpp"
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        std::vector<int> v = {head->val};

        while (head->next != nullptr)
        {
            head = head->next;
            v.push_back(head->val);
        }

        int l = v.size();
        for (int i = 0; i < l / 2; i++)
        {
            if (v[i] != v[l - i - 1])
                return false;
        }

        return true;
    }
};