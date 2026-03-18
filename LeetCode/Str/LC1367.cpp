#include <bits/stdc++.h>
using namespace std;
//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> buildnext(vector<int> &s2, int m)
    {
        if (m == 1)
            return {-1};
        vector<int> next(m);
        next[0] = -1;
        int i = 2, cn = 0;
        while (i < m)
        {
            if (s2[i - 1] == s2[cn])
            {
                next[i++] = ++cn;
            }
            else if (cn > 0)
            {
                cn = next[cn];
            }
            else
            {
                next[i++] = 0;
            }
        }
        return next;
    }
    bool f(vector<int> &s2, vector<int> &next, TreeNode *cur, int i)
    {
        if (i == s2.size())
            return true;
        if (cur == nullptr)
            return false;
        while (i >= 0 && s2[i] != cur->val)
            i = next[i];
        return f(s2, next, cur->left, i + 1) || f(s2, next, cur->right, i + 1);
    }
    bool isSubPath(ListNode *head, TreeNode *root)
    {
        vector<int> s2;
        ListNode *temp = head;
        while (temp != nullptr)
        {
            s2.push_back(temp->val);
            temp = temp->next;
        }
        vector<int> next = buildnext(s2, s2.size());
        return f(s2, next, root, 0);
    }
};