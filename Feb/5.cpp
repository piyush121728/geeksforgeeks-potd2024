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
    Node *sortedInsert(Node *head, int data)
    {
        // Your code here
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            head->next = head;
            return head;
        }
        auto t1 = head;
        auto t2 = t1->next;

        while (1)
        {
            if (t1->data <= data && t2->data >= data)
            {
                t1->next = newNode;
                newNode->next = t2;
                break;
            }

            if (t2 == head)
            {
                t1->next = newNode;
                newNode->next = t2;
                if (data < t2->data)
                {
                    head = newNode;
                }
                break;
            }

            t1 = t2;
            t2 = t2->next;
        }

        return head;
    }
};

// link : https://www.geeksforgeeks.org/problems/sorted-insert-for-circular-linked-list/1