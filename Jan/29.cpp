#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
public:
    stack<int> in, out;
    MyQueue()
    {
    }

    void push(int x)
    {
        in.push(x);
    }

    int pop()
    {
        if (empty())
        {
            return 0;
        }

        if (out.empty())
        {
            while (!in.empty())
            {
                out.push(in.top());
                in.pop();
            }
        }

        int ele = out.top();
        out.pop();
        return ele;
    }

    int peek()
    {
        if (empty())
        {
            return 0;
        }

        if (out.empty())
        {
            while (!in.empty())
            {
                out.push(in.top());
                in.pop();
            }
        }

        return out.top();
    }

    bool empty()
    {
        if (in.empty() && out.empty())
        {
            return 1;
        }
        return 0;
    }
};

