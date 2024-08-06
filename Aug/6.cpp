#include<bits/stdc++.h>
using namespace std;

/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution
{
public:
    int isValid(string str)
    {
        // code here
        stringstream ss(str);
        string w;
        int cnt = 0;
        while (getline(ss, w, '.'))
        {
            if (w.size() == 0 || (w.size() > 1 && w[0] == '0'))
            {
                return false;
            }
            int num = stoi(w);
            if (num >= 0 && num <= 255)
            {
                cnt++;
            }
            else
            {
                return false;
            }
        }

        return cnt == 4;
    }
};

// link : https://www.geeksforgeeks.org/problems/validate-an-ip-address-1587115621/1