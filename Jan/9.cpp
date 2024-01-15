#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void findLps(string pattern, vector<int> &lps)
    {
        int m = pattern.length();
        int len = 0;

        lps[0] = 0;

        int i = 1;
        while (i < m)
        {
            if (pattern[i] == pattern[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if (len != 0)
                {
                    len = lps[len - 1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    vector<int> search(string pat, string txt)
    {
        int n = txt.length();
        int m = pat.length();
        vector<int> result;

        vector<int> lps(m, 0);
        findLps(pat, lps);

        int i = 0;
        int j = 0;

        while (i < n)
        {
            if (pat[j] == txt[i])
            {
                i++;
                j++;
            }

            if (j == m)
            {
                result.push_back(i - j + 1);
                j = lps[j - 1];
            }
            else if (i < n && pat[j] != txt[i])
            {
                if (j != 0)
                {
                    j = lps[j - 1];
                }
                else
                {
                    i++;
                }
            }
        }

        return result;
    }
};

int main()
{
    return 0;
}

// link : https://www.geeksforgeeks.org/problems/search-pattern0205/1