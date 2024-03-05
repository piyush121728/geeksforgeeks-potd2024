#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
    int peakElement(int arr[], int n)
    {
       // Your code here
       int res = -1;

       for(int i = 0; i < n; i++){
           int found = true;

           for(int l = i - 1 ; l >= 0; l--){
               if(arr[i]<arr[l]){
                   found = false;
                   break;
               }
           }

           for(int r = i + 1 ; r < n; r++){
               if(arr[i]<arr[i]){
                   found = false;
                   break;
               }
           }

           if(found){
               res = i;
           }
       }

       return res;
    }
    */
    int peakElement(int arr[], int n)
    {
        int l = 0, r = n - 1;
        while (l < r)
        {
            int m = l + ((r - l) / 2);
            if (arr[m] < arr[m + 1])
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }

        return l;
    }
};

// link : https://www.geeksforgeeks.org/problems/peak-element/1