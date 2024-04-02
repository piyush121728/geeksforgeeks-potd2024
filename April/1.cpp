// Merge sort in C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

class Solution
{
public:
    // Merge two subarrays L and M into arr
    void merge(vector<int> &arr, int p, int q, int r, int &ans)
    {

        // Create L ← A[p..q] and M ← A[q+1..r]
        int n1 = q - p + 1;
        int n2 = r - q;

        int L[n1], M[n2];

        for (int i = 0; i < n1; i++)
            L[i] = arr[p + i];
        for (int j = 0; j < n2; j++)
            M[j] = arr[q + 1 + j];

        // Maintain current index of sub-arrays and main array
        int i, j, k;
        i = 0;
        j = 0;
        k = p;

        // Until we reach either end of either L or M, pick larger among
        // elements L and M and place them in the correct position at A[p..r]
        while (i < n1 && j < n2)
        {
            if (L[i] <= M[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = M[j];
                ans += (n1 - i);
                j++;
            }
            k++;
        }

        // When we run out of elements in either L or M,
        // pick up the remaining elements and put in A[p..r]
        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2)
        {
            arr[k] = M[j];
            j++;
            k++;
        }
    }

    // Divide the array into two subarrays, sort them and merge them
    void mergeSort(vector<int> &arr, int l, int r, int &ans)
    {
        if (l < r)
        {
            // m is the point where the array is divided into two subarrays
            int m = l + (r - l) / 2;

            mergeSort(arr, l, m, ans);
            mergeSort(arr, m + 1, r, ans);

            // Merge the sorted subarrays
            merge(arr, l, m, r, ans);
        }
    }

    void inorder(Node *root, vector<int> &v)
    {
        if (!root)
        {
            return;
        }

        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }

    /*You are required to complete below function */
    int pairsViolatingBST(int n, Node *root)
    {
        // your code goes here
        vector<int> v;
        inorder(root, v);
        int ans = 0;
        mergeSort(v, 0, n - 1, ans);

        return ans;
    }
};

// link : https://www.geeksforgeeks.org/problems/pairs-violating-bst-property--212515/1