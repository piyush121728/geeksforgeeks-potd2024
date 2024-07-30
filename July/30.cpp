#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int n, m;
    vector<string> res;
    unordered_map<char, vector<int>> mp;
    void rec(int i, int j, string path, vector<vector<int>> &mat)
    {

        if (i == n - 1 && j == m - 1)
        {
            res.push_back(path);
            return;
        }

        for (auto it : mp)
        {
            int x = i + it.second[0], y = j + it.second[1];
            char key = it.first;
            // cout<<key<<" "<<i<<" "<<j<<endl;
            if (x >= 0 && x < n && y >= 0 && y < m && mat[x][y] == 1)
            {
                // path.push_back(key);
                mat[i][j] = 0;
                rec(x, y, path + key, mat);
                mat[i][j] = 1;
                // path.pop_back();
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &mat)
    {
        // Your code goes here
        if (mat[0][0] == 0)
        {
            return res;
        }
        n = mat.size();
        m = mat[0].size();
        mp.insert({'U', {-1, 0}});
        mp.insert({'D', {1, 0}});
        mp.insert({'R', {0, 1}});
        mp.insert({'L', {0, -1}});
        rec(0, 0, "", mat);
        return res;
    }
};

// link : https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1