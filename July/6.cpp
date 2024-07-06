#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

class Solution
{
public:
    Node *temp = NULL;
    void populateNext(Node *root)
    {
        // code here
        if (!root)
        {
            return;
        }
        populateNext(root->right);
        root->next = temp;
        temp = root;
        populateNext(root->left);
    }
};

// link : https://www.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1