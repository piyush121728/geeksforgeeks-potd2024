#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC : O(n*m)
    /*
    vector<int> search(string pattern, string text)
    {
        // code here.
        vector<int> v;
        int n = pattern.size();
        for (int i = 0; i <= text.size() - n; i++)
        {
            if (text.substr(i, n) == pattern)
            {
                v.push_back(i + 1);
            }
        }

        return v;
    }
    */

   //TC : O(n+m)
    void rabinKarpAlgo(string p, string t, vector<int> &v)
    {
        int n = t.size(), m = p.size();
        int mod = INT_MAX, base = 256;

        int hash = 1;
        for (int i = 0; i < m - 1; i++)
        {
            hash = (hash * base) % mod;
        }

        int pHash = 0, tHash = 0;
        for (int i = 0; i < m; i++)
        {
            pHash = (base * pHash + p[i]) % mod;
            tHash = (base * tHash + t[i]) % mod;
        }

        for (int i = 0; i <= n - m; i++)
        {
            if (pHash == tHash)
            {
                if (t.substr(i, m) == p)
                {
                    v.push_back(i + 1);
                }
            }
            else
            {
                if (i < n - m)
                {
                    tHash = (base * (tHash - t[i] * hash) + t[i + m]) % mod;
                }
                if (tHash < 0)
                {
                    tHash = tHash + mod;
                }
            }
        }
    }

    vector<int> search(string pattern, string text)
    {
        vector<int> v;
        rabinKarpAlgo(pattern, text, v);
        return v;
    }
};
// link : https://www.geeksforgeeks.org/problems/search-pattern-rabin-karp-algorithm--141631/1