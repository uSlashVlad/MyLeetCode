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
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        auto nextNode = head->next;
        head->next = nullptr;

        while (nextNode->next != nullptr)
        {
            auto reallyNext = nextNode->next;
            nextNode->next = head;
            head = nextNode;
            nextNode = reallyNext;
        }
        nextNode->next = head;

        return nextNode;
    }
};

int main()
{
    Solution s;
    s.reverseList(new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5))))));
}
