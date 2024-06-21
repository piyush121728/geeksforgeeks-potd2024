#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string compareFrac(string str)
    {

        // Code here
        string s = "";
        vector<float> v;
        int f = -1;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '/' || str[i] == ',')
            {
                if (str[i] == ',')
                {
                    f = i;
                }
                int a = stoi(s);
                v.push_back(a * 1.0);
                s = "";
            }
            else
            {
                s += str[i];
            }
        }
        int a = stoi(s);
        v.push_back(a * 1.0);
        if (v[0] / v[1] > v[2] / v[3])
        {
            return str.substr(0, f);
        }
        else if (v[0] / v[1] < v[2] / v[3])
        {
            return str.substr(f + 2);
        }
        return "equal";
    }
};

// link : https://www.geeksforgeeks.org/problems/compare-two-fractions4438/1