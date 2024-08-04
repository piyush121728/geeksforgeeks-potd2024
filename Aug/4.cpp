#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int st[], int en[])
    {
        // Your code here
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({en[i], st[i]});
        }
        sort(v.begin(), v.end());
        int c = 1;
        int prevE = v[0].first;
        for (int i = 1; i < n; i++)
        {
            if (prevE < v[i].second)
            {
                prevE = v[i].first;
                c++;
            }
        }
        return c;
    }
};

// link : https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1