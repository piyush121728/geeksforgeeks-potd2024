#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    vector<Node *> res;
    unordered_map<string, int> mp;
    string rec(Node *root)
    {
        if (!root)
        {
            return "#";
        }
        string s = to_string(root->data) + "," + rec(root->left) + "," + rec(root->right);
        if (mp[s] == 1)
        {
            res.push_back(root);
        }
        mp[s]++;
        return s;
    }

    vector<Node *> printAllDups(Node *root)
    {
        // Code here
        res.clear();
        mp.clear();
        rec(root);
        return res;
    }
};

// link : https://www.geeksforgeeks.org/problems/duplicate-subtrees/1