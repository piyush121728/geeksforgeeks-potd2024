#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleElement(int arr[], int n)
    {
        // code here

        vector<int> bits(32);

        for (int i = 0; i < 32; i++)
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                cnt += (1 & (arr[j] >> i));
            }
            bits[i] = (cnt % 3 == 0) ? 0 : 1;
        }

        int num = 0;
        for (int i = 0; i < 32; i++)
        {
            if (bits[i] == 1)
            {
                num += (1 << i);
            }
        }

        return num;
    }
};

int main()
{
    return 0;
}

// link : https://www.geeksforgeeks.org/problems/find-element-occuring-once-when-all-other-are-present-thrice/1