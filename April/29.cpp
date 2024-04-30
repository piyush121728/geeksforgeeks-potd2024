#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    Node *deleteK(Node *head, int k)
    {
        // Your code here

        if (k == 1)
        {
            return NULL;
        }

        int i = 1;
        Node *curr = head;
        Node *prev = NULL;
        while (curr)
        {

            if (i % k == 0)
            {
                prev->next = curr->next;
                curr->next = NULL;
                curr = prev->next;
                i++;
            }

            prev = curr;
            if (curr)
            {
                curr = curr->next;
            }
            i++;
        }
        return head;
    }
};

// link : https://www.geeksforgeeks.org/problems/remove-every-kth-node/1