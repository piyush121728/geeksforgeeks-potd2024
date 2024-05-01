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
    // task is to complete this function
    // function should return head to the list after making
    // necessary arrangements
    struct Node *arrangeCV(Node *head)
    {
        // Code here
        auto curr = head;
        Node *prev = NULL;
        Node *temp = NULL;
        set<int> st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');

        while (curr && st.count(curr->data) > 0)
        {
            prev = curr;
            temp = curr;
            curr = curr->next;
        }

        while (curr)
        {

            if (st.count(curr->data) > 0)
            {
                prev->next = curr->next;
                curr->next = NULL;
                if (temp == NULL)
                {
                    curr->next = head;
                    head = curr;
                }
                else
                {
                    Node *next = temp->next;
                    temp->next = curr;
                    curr->next = next;
                }
                temp = curr;
                curr = prev->next;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }
};

// link : https://www.geeksforgeeks.org/problems/arrange-consonants-and-vowels/1