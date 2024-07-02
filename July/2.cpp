#include <bits/stdc++.h>
using namespace std;

struct Node
{
    string data;
    Node *next;

    Node(string x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    bool compute(Node *head)
    {
        // Your code goes here
        string str = "";
        while (head)
        {
            str += head->data;
            head = head->next;
        }
        string revstr = str;
        reverse(revstr.begin(), revstr.end());
        return str == revstr;
    }
};