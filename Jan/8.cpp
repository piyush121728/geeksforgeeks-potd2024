#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Solution
{
public:
    Node *reverse(Node *node)
    {
        Node* prev = NULL;
        Node* curr = node;
        
        while(curr){
            auto next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        // your code goes here
        if(!node1 && !node2){
            return NULL;
        }
        
        if(!node1){
            return reverse(node2);
        }
        
        if(!node2){
            return reverse(node1);
        }
        
        Node* head = NULL;
        Node* tail = NULL;
        
        while(node1 && node2){
            Node* newNode = NULL;
            
            if(node1->data <= node2->data)
            {
                newNode = node1;
                node1 = node1->next;
                newNode->next = NULL;
            }
            else{
                newNode = node2;
                node2 = node2->next;
                newNode->next = NULL;
            }
            
            if(!head){
                head = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = newNode;
            }
            
        }
        
        if(!node1){
            tail->next = node2;
        }
        
        if(!node2){
            tail->next = node1;
        }
        
        
        return reverse(head); 
    }  
};

int main(){
    return 0;
}

// link : https://www.geeksforgeeks.org/problems/merge-2-sorted-linked-list-in-reverse-order/1