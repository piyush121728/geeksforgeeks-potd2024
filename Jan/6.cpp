#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int num)
    {
        int points = 0;
        int n = num;
        for (int i = 2; i <= sqrt(n); i++)
        {
            while (num % i == 0)
            {
                num /= i;
                points++;
            }
        }

        if (num != 1)
        {
            points++;
        }

        return points;
    }

    int sumOfPowers(int a, int b)
    {
        // Code here
        int res = 0;
        for (int i = a; i <= b; i++)
        {
            res += solve(i);
        }

        return res;
    }
};

int main()
{
    return 0;
}

// link : https://www.geeksforgeeks.org/problems/techfest-and-the-queue1044/1