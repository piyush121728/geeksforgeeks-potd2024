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
    // Function to return a tree created from post and inoreder traversals.
    Node *buildTreeHelper(int in[], int is, int ie, int post[], int ps, int pe)
    {
        // base case
        if (ps > pe && is > ie)
        {
            return NULL;
        }

        // my work
        // creation of root node
        Node *root = new Node(post[pe]);

        int rootData = post[pe];
        int rootIndex = -1; // for in
        for (int i = is; i <= ie; i++)
        {
            if (in[i] == rootData)
            {
                rootIndex = i;
                break;
            }
        }

        int lis = is;
        int lie = rootIndex - 1;
        int lps = ps;
        int lpe = lie - lis + lps;

        // recursive call or induction hypothesis
        // formation of leftSubTree using recursion
        Node *leftSubTree = buildTreeHelper(in, lis, lie, post, lps, lpe);

        // my work
        int rps = lpe + 1;
        int rpe = pe - 1;
        int ris = rootIndex + 1;
        int rie = ie;

        // recursive call or induction hypothesis
        // formation of rightSubTree using recursion
        Node *rightSubTree = buildTreeHelper(in, ris, rie, post, rps, rpe);

        // induction step
        // formation of complete tree
        root->left = leftSubTree;
        root->right = rightSubTree;

        return root;
    }

    Node *buildTree(int in[], int post[], int n)
    {
        // Your code here
        return buildTreeHelper(in, 0, n - 1, post, 0, n - 1);
    }
};

//link :  https://www.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1