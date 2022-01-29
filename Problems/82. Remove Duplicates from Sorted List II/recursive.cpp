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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *point = head->next;

        if (point->val != head->val)
        {
            head->next = deleteDuplicates(point);
            return head;
        }
        else
        {
            while (point != nullptr && point->val == head->val)
                point = point->next;
            return deleteDuplicates(point);
        }
    }
};
