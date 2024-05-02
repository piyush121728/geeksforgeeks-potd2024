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
    // Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root)
    {
        // Your code here
        vector<int> v;
        queue<Node *> pn;
        pn.push(root);
        v.push_back(root->data);

        while (!pn.empty())
        {
            auto node = pn.front();
            pn.pop();

            if (node->left)
            {
                v.push_back(node->left->data);
                pn.push(node->left);
            }
            else
            {
                v.push_back(-1);
            }

            if (node->right)
            {
                v.push_back(node->right->data);
                pn.push(node->right);
            }
            else
            {
                v.push_back(-1);
            }
        }

        return v;
    }

    // Function to deserialize a list and construct the tree.
    Node *deSerialize(vector<int> &v)
    {
        // Your code here
        // for(auto x:v){
        //     cout<<x<<" ";
        // }
        // cout<<endl;

        Node *root = new Node(v[0]);
        queue<Node *> pn;
        pn.push(root);
        int i = 1;
        while (!pn.empty())
        {
            auto node = pn.front();
            pn.pop();

            if (v[i] != -1)
            {
                node->left = new Node(v[i]);
                pn.push(node->left);
                // cout<<node->left->data<<endl;
            }
            i++;

            if (v[i] != -1)
            {
                node->right = new Node(v[i]);
                pn.push(node->right);
                // cout<<node->right->data<<endl;
            }
            i++;
        }

        return root;
    }
};

// link :https://www.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1