#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> search(string pat, string txt)
    {
        // code here

        int n = txt.size();
        int k = pat.size();

        if (k > n)
        {
            return {-1};
        }

        vector<int> v;

        for (int i = 0; i < n - k; i++)
        {

            if (pat == txt.substr(i, k))
            {
                v.push_back(1);
            }
        }

        if (v.size() == 0)
        {
            return {-1};
        }

        return v;
    }
};

int main()
{
    return 0;
}