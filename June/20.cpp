#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long gcd(long long a, long long b)
    {
        while (b != 0)
        {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    long long InternalCount(long long p[], long long q[], long long r[])
    {
        long long area = abs(p[0] * (q[1] - r[1]) + q[0] * (r[1] - p[1]) + r[0] * (p[1] - q[1])) / 2;

        long long boundaryPoints = gcd(abs(p[0] - q[0]), abs(p[1] - q[1])) +
                                   gcd(abs(q[0] - r[0]), abs(q[1] - r[1])) +
                                   gcd(abs(r[0] - p[0]), abs(r[1] - p[1]));
        long long interiorPoints = area - (boundaryPoints / 2) + 1;

        return interiorPoints;
    }
};

// link : https://www.geeksforgeeks.org/problems/integral-points-in-triangle5026/1