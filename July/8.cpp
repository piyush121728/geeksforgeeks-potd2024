#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &arr, int key)
    {
        // complete the function here
        // modified binary search
        // in modified binary search first we look for sorted subarray then
        // we will apply binary search on that sorted subarray

        int n = arr.size(), l = 0, h = n - 1;
        int res = -1;
        while (l <= h)
        {
            int mid = l + (h - l) / 2;

            // check whether the left subarray is sorted or not

            if (arr[mid] == key)
            {
                res = mid;
                break;
            }

            if (arr[mid] >= arr[l])
            {
                // now we will look whether the key is lie in left subarray or not
                if (key >= arr[l] && key <= arr[mid])
                {
                    h = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else
            { // check whether the right subarray is sorted or not
                // now we will look whether the key is lie in right subarray or not
                if (key >= arr[mid] && key <= arr[h])
                {
                    l = mid + 1;
                }
                else
                {
                    h = mid - 1;
                }
            }
        }
        return res;
    }
};

// link : https://www.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1