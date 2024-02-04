
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    bool data; // NOTE data is bool
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    // Should return decimal equivalent modulo 1000000007 of binary linked list
    long long unsigned int decimalValue(Node *head)
    {
        // Your Code Here
        int mod = 1e9 + 7;
        // reverse the linked list
        Node *prev = NULL;
        while (head)
        {
            Node *next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        long long unsigned int ans = 0, pow = 1;
        while (prev)
        {
            if (prev->data)
                ans = (ans + pow) % mod;
            pow = (pow * 2) % mod;
            prev = prev->next;
        }
        return ans % mod;
    }
};

// link : https://www.geeksforgeeks.org/problems/decimal-equivalent-of-binary-linked-list/1