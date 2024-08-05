#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        map<int,int> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(q.size()!=0){
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int dist = it.second;
            
            mp[dist] = node->data;
            if(node->left){
                q.push({node->left,dist-1});
            }
            if(node->right){
                q.push({node->right,dist+1});
            }
        }
        vector<int> ans;
        for(auto it:mp){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};

// link : https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1