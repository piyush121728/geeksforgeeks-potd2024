#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node
{
public:
    int data;
    Node *next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList
{
public:
    Node *head;
    Node *tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val)
    {
        if (head == NULL)
        {
            head = new Node(val);
            tail = head;
        }
        else
        {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    string trimZero(string str)
    {
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] != '0')
            {
                return str.substr(i);
            }
        }
        return "";
    }

    int carry = 0;
    string subtract(string s, string t)
    {
        int n = s.size(), m = t.size();
        int k = abs(n - m);
        string str(k, '0');
        t = str + t;

        int carry = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            int num1 = s[i] - '0', num2 = t[i] - '0';
            // cout<<num1<<" "<<num2<<endl;
            num1 -= carry;
            int diff = (num1 - num2);
            carry = 0;
            if (diff < 0)
            {
                diff = ((10 + num1) - num2);
                carry = 1;
            }

            s[i] = '0' + diff;
        }

        return s;
    }

    Node *subLinkedList(Node *head1, Node *head2)
    {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list]
        string num1 = "";
        while (head1)
        {
            num1 += ('0' + head1->data);
            head1 = head1->next;
        }
        string num2 = "";
        while (head2)
        {
            num2 += ('0' + head2->data);
            head2 = head2->next;
        }

        num1 = trimZero(num1);
        num2 = trimZero(num2);

        int n = num1.size(), m = num2.size();

        // cout<<num1<<" "<<num2<<endl;

        string str = "";
        if (n > m)
        {
            str = subtract(num1, num2);
        }
        else if (m > n)
        {
            str = subtract(num2, num1);
        }
        else
        {

            for (int i = 0; i < n; i++)
            {
                if (num1[i] > num2[i])
                {
                    str = subtract(num1, num2);
                    break;
                }
                else if (num2[i] > num1[i])
                {
                    str = subtract(num2, num1);
                    break;
                }
            }
        }

        str = trimZero(str);
        if (str.size() == 0)
        {
            return new Node(0);
        }
        Node *h = NULL;
        Node *c = NULL;

        for (auto ch : str)
        {
            Node *newNode = new Node(ch - '0');
            if (!h)
            {
                h = newNode;
            }
            else
            {
                c->next = newNode;
            }
            c = newNode;
        }

        return h;
    }
};

// link : https://www.geeksforgeeks.org/problems/subtraction-in-linked-list/1