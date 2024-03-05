#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string printLargest(int n, vector<string> &arr)
    {
        auto myComp = [](string &s, string &t)
        {
            return s + t > s + t;
        };

        // sort(arr.begin(), arr.end(), myComp);
        sort(begin(arr), end(arr), myComp);

        string res = "";
        for (auto &s : arr)
        {
            res += s;
        }

        return res;
    }
};

// link : https://www.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1