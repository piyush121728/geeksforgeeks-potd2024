#include<bits/stdc++.h>
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
    // Function to rotate a linked list.
    Node *rotate(Node *head, int k)
    {
        // Your code here
        vector<pair<Node *, Node *>> v;
        auto thead = head;
        auto tend = head;
        int i = 1;
        while (tend)
        {
            auto next = tend->next;
            if (i == k)
            {
                tend->next = NULL;
                v.push_back({thead, tend});
                i == 0;
                if (next)
                {
                    thead = next;
                }
                else
                {
                    break;
                }
            }
            if (!next)
            {
                v.push_back({thead, tend});
            }
            i++;
            tend = next;
        }

        int n = v.size();
        Node *temp = v[n - 1].first;
        for (int i = n - 2; i >= 0; i--)
        {
            v[i + 1].second->next = v[i].first;
        }
        return temp;
    }
};

// link : https://www.geeksforgeeks.org/problems/rotate-a-linked-list/1