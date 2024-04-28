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
    struct Node *getMiddle(Node *h1)
    {
        Node *fast = h1;
        Node *slow = h1;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node *temp = slow->prev;
        slow->prev = NULL;
        temp->next = NULL;

        return slow;
    }
    struct Node *merge(Node *h1, Node *h2)
    {
        Node *h = new Node(-1);
        Node *curr = h;
        while (h1 != NULL && h2 != NULL)
        {
            if (h1->data < h2->data)
            {
                curr->next = h1;
                h1->prev = curr;

                h1 = h1->next;
            }
            else
            {
                curr->next = h2;
                h2->prev = curr;

                h2 = h2->next;
            }
            curr = curr->next;
        }

        if (h1 != NULL)
        {
            curr->next = h1;
            h1->prev = curr;
        }
        if (h2 != NULL)
        {
            curr->next = h2;
            h2->prev = curr;
        }

        h->next->prev = NULL;
        return h->next;
    }
    struct Node *sortDoubly(Node *h1)
    {

        if (h1 == NULL || h1->next == NULL)
        {
            return h1;
        }

        Node *h2 = getMiddle(h1);
        h1 = sortDoubly(h1);
        h2 = sortDoubly(h2);

        return merge(h1, h2);
    }
};



// https://www.geeksforgeeks.org/problems/merge-sort-on-doubly-linked-list/1