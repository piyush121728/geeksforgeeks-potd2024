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
    // Function to add two numbers represented by linked list.
    Node *reverse(Node *head)
    {
        Node *prev = NULL, *curr = head, *nxt = NULL;
        while (curr)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }

    struct Node *addTwoLists(struct Node *num1, struct Node *num2)
    {
        // code here
        Node *temp = NULL;
        while (num1 and num1->data == 0)
        {
            temp = num1;
            num1 = num1->next;
        }
        if (temp)
            temp->next = NULL;
        temp = NULL;
        while (num2 and num2->data == 0)
        {
            temp = num2;
            num2 = num2->next;
        }
        if (temp)
            temp->next = NULL;
        if (!num1 and !num2)
            return new Node(0);
        if (!num1)
            return num2;
        if (!num2)
            return num1;
        num1 = reverse(num1);
        num2 = reverse(num2);
        temp = new Node(1);
        Node *head1 = num1, *head2 = num2, *thead = temp;
        int c = 0;
        while (head1 and head2)
        {
            int x = head1->data + head2->data + c;
            c = x / 10;
            temp->next = new Node(x % 10);
            temp = temp->next;
            head1 = head1->next;
            head2 = head2->next;
        }
        while (head1)
        {
            int x = head1->data + c;
            c = x / 10;
            temp->next = new Node(x % 10);
            temp = temp->next;
            head1 = head1->next;
        }
        while (head2)
        {
            int x = head2->data + c;
            c = x / 10;
            temp->next = new Node(x % 10);
            temp = temp->next;
            head2 = head2->next;
        }
        if (c)
            temp->next = new Node(c);
        return reverse(thead->next);
    }
};

// link : https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1