#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        string minStr;
        int n = arr.size(), minSize = INT_MAX;
        for(auto x:arr){
            int s = x.size();
            if(s<minSize){
                minStr = x;
                minSize = s;
            }
        }
        
        string ans = "-1";
        for(int i = 0; i < minSize; i++){
            string prefix = minStr.substr(0,i+1);
            // cout<<prefix<<endl;
            int j = 0;
            for(; j < n; j++){
                if(prefix!=arr[j].substr(0,i+1)){
                    break;
                }
            }
            if(j==n){
                ans = prefix;
            }
        }
        
        return ans;
    }
};

// link : https://www.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1