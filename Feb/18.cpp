#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
};

class Solution
{
public:
    void solve(Node *root, int &sum)
    {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL)
        {
            sum += root->data;
        }
        solve(root->left, sum);
        solve(root->right, sum);
    }
    int sumOfLeafNodes(Node *root)
    {
        int sum = 0;
        solve(root, sum);
        return sum;
    }
};