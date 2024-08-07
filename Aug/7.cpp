#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kthElement(int k, vector<int> &arr1, vector<int> &arr2)
    {
        // code here
        vector<int> finalArr;

        int n = arr1.size(), m = arr2.size(), i = 0, j = 0;

        while (i < n && j < m)
        {
            if (arr1[i] < arr2[j])
            {
                finalArr.push_back(arr1[i]);
                i++;
            }
            else if (arr2[j] < arr1[i])
            {
                finalArr.push_back(arr2[j]);
                j++;
            }
            else
            {
                finalArr.push_back(arr1[i]);
                finalArr.push_back(arr2[j]);
                i++;
                j++;
            }
        }

        while (i < n)
        {
            finalArr.push_back(arr1[i]);
            i++;
        }
        while (j < m)
        {
            finalArr.push_back(arr2[j]);
            j++;
        }

        return finalArr[k - 1];
    }
};

// link : https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1