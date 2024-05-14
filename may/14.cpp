#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int MinimumEffort(int n, int m, vector<vector<int>> &heights)
    {
        // code here

        // to store the min effort to reach at every cell form src(0,0) cells
        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        // pair<minEffort,pair<row,col>>
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        // min effort of src cell
        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        // to iterate in 4 direction left, right, top and bottom
        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int r = it.second.first;
            int c = it.second.second;

            // when we counted top's row and col is equal to dest row and dest col respectively, then pop'f diff will be ans
            if (r == n - 1 && c == m - 1)
            {
                return diff;
            }

            // now, we will move in all four given direction directions(left, right, top and bottom)
            for (int i = 0; i < 4; i++)
            {
                int newr = delrow[i] + r;
                int newc = delcol[i] + c;

                // logic
                if (newr < n && newr >= 0 && newc < m && newc >= 0)
                {
                    // calculation of new effort for adajcent cell of current cell(intially all cell is fill with 1e9)
                    int absDiff = abs(heights[r][c] - heights[newr][newc]);
                    int newEffort = max(absDiff, diff);
                    // when the newly calculated effort is lesser than the old effort
                    // then we update the effort of that cell
                    // and push the cell position and newly updated min effort of cell into priority queue
                    if (newEffort < dist[newr][newc])
                    {
                        dist[newr][newc] = newEffort;
                        pq.push({newEffort, {newr, newc}});
                    }
                }
            }
        }

        return 0;
    }
};

// link : https://www.geeksforgeeks.org/problems/path-with-minimum-effort/1