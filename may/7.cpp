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

vector<int> reverseLevelOrder(Node *root)
{
    // code here
    vector<vector<int>> v;
    queue<Node *> pn;
    pn.push(root);

    while (!pn.empty())
    {
        int s = pn.size();
        vector<int> temp;
        while (s--)
        {
            auto node = pn.front();
            pn.pop();
            temp.push_back(node->data);
            if (node->left)
            {
                pn.push(node->left);
            }
            if (node->right)
            {
                pn.push(node->right);
            }
        }
        v.push_back(temp);
    }

    reverse(v.begin(),v.end());
    vector<int> ans;
    for(auto x:v){
        for(auto y:x){
            ans.push_back(y);
        }
    }
    v.clear();
    return ans;
}

// link : https://www.geeksforgeeks.org/problems/reverse-level-order-traversal/1