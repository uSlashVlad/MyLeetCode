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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr)
            if (list2 == nullptr)
                return nullptr;
            else
                return list2;
        else if (list2 == nullptr)
            return list1;

        if (list1->val > list2->val)
        {
            list1 = new ListNode(list2->val, list1);
            list2 = list2->next;
        }

        auto initialList1 = list1;

        while (list2 != nullptr)
        {
            if (list1->next == nullptr || list2->val <= list1->next->val)
            {
                auto newElem = new ListNode(list2->val, list1->next);
                list1->next = newElem;
                list1 = newElem;
                list2 = list2->next;
            }
            else
            {
                list1 = list1->next;
            }
        }

        return initialList1;
    }
};
