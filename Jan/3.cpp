#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int smallestSubstring(string S)
    {
        // Code here
        int cnt = -1;
        int n = S.size();

        vector<int> freq(n, 0);

        int j = 0;
        int i = 0;
        while (i < n)
        {
            freq[S[i] - '0']++;
            if (freq[0] > 0 && freq[1] > 0 && freq[2] > 0)
            {
                break;
            }
            i++;
        }

        if (i == n)
        {
            return cnt;
        }

        cnt = i + 1;

        while (i < n)
        {

            while (j < i && (freq[0] > 0 && freq[1] > 0 && freq[2] > 0))
            {
                freq[S[j] - '0']--;
                j++;
                if (freq[0] > 0 && freq[1] > 0 && freq[2] > 0)
                {
                    cnt = min(i - j + 1, cnt);
                }
                else
                {
                    break;
                }
            }

            freq[S[i] - '0']++;
            i++;
        }

        return cnt;
    }
};

int main(){
    return 0;
}

// link : https://www.geeksforgeeks.org/problems/smallest-window-containing-0-1-and-2--170637/1