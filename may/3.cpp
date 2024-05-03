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
    // function should print the nodes at k distance from root
    vector<int> Kdistance(struct Node *root, int k)
    {
        // Your code here
        vector<int> ans;
        queue<Node *> pn;
        pn.push(root);

        while (!pn.empty())
        {

            int len = pn.size();

            for (int i = 0; i < len; i++)
            {
                auto node = pn.front();
                pn.pop();
                if (k == 0)
                {
                    ans.push_back(node->data);
                }
                if (node->left)
                {
                    pn.push(node->left);
                }
                if (node->right)
                {
                    pn.push(node->right);
                }
            }
            if (k == 0)
            {
                break;
            }
            k--;
        }
        return ans;
    }
};