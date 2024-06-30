#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;

    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

class Solution
{
public:
    Node *deleteNode(Node *head, int x)
    {
        // Your code here
        Node *temp = head;
        while (x--)
        {
            if (x == 0)
            {
                Node *prev = temp->prev;
                Node *next = temp->next;

                if (prev == NULL)
                {
                    next->prev = prev;
                    temp->next = NULL;
                    head = next;
                }
                else if (next == NULL)
                {
                    prev->next = next;
                    temp->prev = NULL;
                }
                else
                {
                    prev->next = next;
                    next->prev = prev;
                }
                break;
            }
            temp = temp->next;
        }
        return head;
    }
};

// link : https://www.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1