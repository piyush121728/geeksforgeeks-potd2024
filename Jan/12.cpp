#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k)
    {
        // add code here.
        int n = k;
        int m = q.size();
        vector<int> v;
        while (k--)
        {
            v.push_back(q.front());
            q.pop();
        }
        k = v.size();
        while (k--)
        {
            q.push(v.back());
            v.pop_back();
        }

        for (int i = n; i < m; i++)
        {
            q.push(q.front());
            q.pop();
        }

        return q;
    }
};

int main(){
    return 0;
}