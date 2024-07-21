#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
class Solution
{
public:
    Node *RemoveHalfNodes(Node *root)
    {
        // code here
        if (!root)
            return NULL;
        root->left = RemoveHalfNodes(root->left);
        root->right = RemoveHalfNodes(root->right);
        if (!root->left and root->right)
        {
            Node *temp = root->right;
            root->right = NULL;
            return temp;
        }
        else if (root->left and !root->right)
        {
            Node *temp = root->left;
            root->left = NULL;
            return temp;
        }

        return root;
    }
};