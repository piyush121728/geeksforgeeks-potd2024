#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
        : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{

public:
    int n;
    Node *buildBST(vector<int> &nums, int left, int right)
    {
        if (left > right)
        {
            return NULL;
        }
        int mid = (left + right) / 2;

        Node *root = new Node(nums[mid]);
        root->left = buildBST(nums, left, mid - 1);
        root->right = buildBST(nums, mid + 1, right);
        return root;
    }
    Node *sortedArrayToBST(vector<int> &nums)
    {
        // Code here
        n = nums.size();
        return buildBST(nums, 0, n - 1);
    }
};

// link : https://www.geeksforgeeks.org/problems/array-to-bst4443/1