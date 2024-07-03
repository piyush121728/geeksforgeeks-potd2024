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
    Node *removeAllDuplicates(struct Node *head)
    {
        // code here
        map<int, int> mp;

        while (head)
        {
            mp[head->data]++;
            head = head->next;
        }

        Node *thead = NULL;
        Node *temp = NULL;

        for (auto it : mp)
        {
            if (it.second == 1)
            {
                if (!thead)
                {
                    thead = new Node(it.first);
                    temp = thead;
                }
                else
                {
                    temp->next = new Node(it.first);
                    temp = temp->next;
                }
            }
        }

        return thead;
    }
};

// link : https://www.geeksforgeeks.org/problems/remove-all-occurences-of-duplicates-in-a-linked-list/1