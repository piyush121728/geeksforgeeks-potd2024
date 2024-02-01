#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to check if a string is Pangram or not.
    bool checkPangram(string s)
    {
        // your code here
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        set<char> ch;
        for (auto x : s)
        {
            if (x >= 'a' && x <= 'z')
            {
                ch.insert(x);
            }
        }

        return ch.size() == 26;
    }
};