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
    // Function to construct binary tree from parent array.
    Node *createTree(vector<int> parent)
    {
        // Your code here
        int rootData = -1, n = parent.size();
        vector<vector<int>> adj(n, vector<int>());
        for (int child = 0; child < n; child++)
        {
            if (parent[child] == -1)
            {
                rootData = child;
            }
            else
            {
                adj[parent[child]].push_back(child);
            }
        }

        queue<Node *> pn;
        Node *root = new Node(rootData);
        pn.push(root);
        while (!pn.empty())
        {
            auto par = pn.front();
            pn.pop();

            if (adj[par->data].size() > 0)
            {
                par->left = new Node(adj[par->data][0]);
                pn.push(par->left);
                if (adj[par->data].size() == 2)
                {
                    par->right = new Node(adj[par->data][1]);
                    pn.push(par->right);
                }
            }
        }
        return root;
    }
};

// link : https://www.geeksforgeeks.org/problems/construct-binary-tree-from-parent-array/1