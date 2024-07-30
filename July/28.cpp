#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeDups(string str)
    {
        // Your code goes here
        unordered_map<char,int> mp;
        string res = "";
        for(auto ch:str){
            if(mp[ch]==0){
                res+=ch;
            }
            mp[ch]++;
        }
        return res;
    }
};

// link : https://www.geeksforgeeks.org/problems/remove-duplicates3034/1