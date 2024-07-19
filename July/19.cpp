#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pbds                                              \
    tree<pair<int, int>, null_type, less<pair<int, int>>, \
         rb_tree_tag, tree_order_statistics_node_update>
using namespace __gnu_pbds;
using namespace std;

class Solution
{
public:
    vector<int> constructLowerArray(vector<int> &arr)
    {

        pbds s;
        int n = arr.size();
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--)
        {

            ans[i] = s.order_of_key({arr[i], i});
            s.insert({arr[i], i});
        }

        return ans;
    }
};

// link : https://www.geeksforgeeks.org/problems/count-smaller-elements2214/1