#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next, *prev;
    Node(int x)
    {
        data = x;
        next = prev = NULL;
    }
};

class Solution
{
public:
    Node *deleteMid(Node *h1)
    {
        // Your Code Here
        Node *fast = h1;
        Node *slow = h1;
        Node *prev = NULL;
        while (fast != NULL && fast->next != NULL)
        { // odd and even case
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;
        return h1;
    }
};

// link : https://www.geeksforgeeks.org/problems/delete-middle-of-linked-list/1