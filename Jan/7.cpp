#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(int arr[], int n, int k, int limit)
    {
        int cnt = 1;
        int sum = arr[0];

        for (int i = 1; i < n; i++)
        {
            if (sum + arr[i] <= limit)
            {
                sum += arr[i];
            }
            else
            {
                sum = arr[i];
                cnt++;
            }
        }

        return cnt;
    }

    int splitArray(int arr[], int N, int K)
    {
        // code here
        int low = INT_MIN;
        int high = 0;
        for (int i = 0; i < N; i++)
        {
            low = max(low, arr[i]);
            high += arr[i];
        }

        while (low <= high)
        {
            int mid = (low + high) / 2;
            int cnt = solve(arr, N, K, mid);

            if (cnt > K)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return low;
    }
};
int main()
{
    return 0;
}

// link : https://www.geeksforgeeks.org/problems/split-array-largest-sum--141634/1