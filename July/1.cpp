#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Function to make binary tree from linked list.
TreeNode *constructTree(int i, int n, vector<int> &v)
{
    if (i >= n)
    {
        return NULL;
    }

    TreeNode *root = new TreeNode(v[i]);
    root->left = constructTree(2 * i + 1, n, v);
    root->right = constructTree(2 * i + 2, n, v);
    return root;
}
void convert(Node *head, TreeNode *&root)
{
    // Your code here
    vector<int> v;
    while (head)
    {
        v.push_back(head->data);
        head = head->next;
    }

    int n = v.size();
    root = constructTree(0, n, v);
}

// link :https://www.geeksforgeeks.org/problems/make-binary-tree/1