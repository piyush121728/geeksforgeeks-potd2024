#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumLength(vector<int> &nums)
    {
        unordered_map<long long, int> mp;
        for (auto num : nums)
        {
            mp[num]++;
        }

        int ans = 1;
        for (auto [num, freq] : mp)
        {
            if (num == 1)
            {
                ans = (freq % 2 == 0) ? max(ans, freq - 1) : max(ans, freq);
                continue;
            }

            int len = 0;
            if (freq >= 2)
            {
                len += 2;
                long long n = num;
                n = num * num;
                while (mp.count(n))
                {
                    if (mp[n] >= 2)
                    {
                        len += 2;
                    }
                    else if (mp[n] == 1)
                    {
                        len += 1;
                        break;
                    }
                    n = n * n;
                }
                ans = (len % 2 == 0) ? max(ans, len - 1) : max(ans, len);
            }
        }
        return ans;
    }
};
int main()
{
    cout << "Hello" << endl;
    return 0;
}