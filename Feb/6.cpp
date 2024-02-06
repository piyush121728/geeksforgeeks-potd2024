#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Solution
{
public:
    // Function to return count of nodes at a given distance from leaf nodes.
    int cnt = 0;
    bool isSpecial(Node *root, int k, int lvl)
    {
        if (!root)
        {
            return false;
        }

        if (lvl == k)
        {
            if (!root->left && !root->right)
            {
                return true;
            }
            return false;
        }

        return isSpecial(root->left, k, lvl + 1) || isSpecial(root->right, k, lvl + 1);
    }

    void solve(Node *root, int k)
    {
        if (!root)
        {
            return;
        }
        if (isSpecial(root, k, 0))
        {
            cnt++;
        }
        solve(root->left, k);
        solve(root->right, k);
    }
    int printKDistantfromLeaf(Node *root, int k)
    {
        // Add your code here.
        solve(root, k);
        return cnt;
    }
};

// link : https://www.geeksforgeeks.org/problems/node-at-distance/1