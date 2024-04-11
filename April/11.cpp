#include <bits/stdc++.h>
using namespace std;

int grayToBinary(int n)
{

    // Your code here
    // decimal to binary
    if(n==0){
        return 0;
    }
    vector<int> binary;
    while (n != 0)
    {
        if (n & 1 == 1)
        {
            binary.push_back(1);
        }
        else
        {
            binary.push_back(0);
        }
        n /= 2;
    }
    reverse(binary.begin(), binary.end());
   
    // binary to gray
    int N = binary.size();
    vector<int> gray(N, 0);
    gray[0] = binary[0];
    for (int i = 1; i < N; i++)
    {
        gray[i] = gray[i - 1] ^ binary[i];
    }
    
    // binary equivalent of gray
    int num = 0;
    reverse(gray.begin(), gray.end());

    for (int i = 0; i < N; i++)
    {
        num += (gray[i] << i);
    }
    return num;
}

// link : https://www.geeksforgeeks.org/problems/gray-to-binary-equivalent-1587115620/1