#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

class Solution
{
    // Function to find the maximum profit and the number of job
public:
    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        // your code here
        int maxiD = -1;
        vector<pair<int, pair<int, int>>> v;
        for (int i = 0; i < n; i++)
        {
            int b = arr[i].id, d = arr[i].dead, p = arr[i].profit;
            v.push_back({p, {b, d}});
            maxiD = max(maxiD, d);
        }
        sort(v.begin(), v.end());
        vector<int> c(maxiD, -1);
        int cnt = 0, totP = 0;
        for (int k = n - 1; k >= 0; k--)
        {
            int b = v[k].second.first, d = v[k].second.second, p = v[k].first;
            if (c[d - 1] == -1)
            {
                c[d - 1] = b;
                totP += p;
                cnt++;
            }
            else
            {
                int i = d - 1;
                while (i >= 0 && c[i] != -1)
                {
                    i--;
                }

                if (i >= 0)
                {
                    c[i] = b;
                    totP += p;
                    cnt++;
                }
            }
        }

        return {cnt, totP};
    }
};

// link : https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1