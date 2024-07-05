#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{
public:
    // Function to find the vertical width of a Binary Tree.
    void rec(Node *root, int i, int &mini, int &maxi)
    {
        if (!root)
        {
            return;
        }
        mini = min(i, mini);
        maxi = max(i, maxi);
        rec(root->left, i - 1, mini, maxi);
        rec(root->right, i + 1, mini, maxi);
    }
    int mini = INT_MAX, maxi = INT_MIN;
    int verticalWidth(Node *root)
    {
        // code here
        if (!root)
        {
            return 0;
        }
        rec(root, 0, mini, maxi);
        // cout<<mini<<" "<<maxi<<endl;
        return maxi - mini + 1;
    }
};

// link : https://www.geeksforgeeks.org/problems/vertical-width-of-a-binary-tree/1