#include "../includes.hpp"
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == nullptr)
            return nullptr;

        connectWithParent(root->left, root);
        connectWithParent(root->right, root);

        return root;
    }

    Node *connectWithParent(Node *root, Node *parent)
    {
        if (root == nullptr)
            return nullptr;

        if (root == parent->left)
            root->next = parent->right;
        else if (parent->next == nullptr)
            root->next = nullptr;
        else
            root->next = parent->next->left;

        connectWithParent(root->left, root);
        connectWithParent(root->right, root);

        return root;
    }
};