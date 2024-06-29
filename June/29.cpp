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

bool areIdentical(struct Node *head1, struct Node *head2)
{
    // Code here
    while (head1 && head2)
    {
        if (head1->data != head2->data)
        {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return head1 == NULL && head2 == NULL;
}

// link : https://www.geeksforgeeks.org/problems/identical-linked-lists/1