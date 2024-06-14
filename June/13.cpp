#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int padovanSequence(int n) {
        // code here.
        int n_1 = 1, n_2 = 1, n_3 = 1;
        
        for(int i = 3; i <= n; i++){
            int curr = (n_1 + n_2)%1000000007;
            n_1 = n_2;
            n_2 = n_3;
            n_3 = curr;
        }
        
        return n_3;
    }
};

// link : https://www.geeksforgeeks.org/problems/padovan-sequence2855/1