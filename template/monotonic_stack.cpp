#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n), f(n);
    for (int &x : a)
        cin >> x;
    stack<int> b;
    for (int i = 0; i < n; i++)
    {
        // while (!b.empty() && a[b.top()] < a[i])
        // {
        //     f[b.top()] = i;
        //     b.pop();
        // }
        // b.push(i);
        // 如果栈为空，直接将当前索引压入栈
        if (b.empty())
        {
            b.push(i);
        }
        // 如果栈顶的元素大于当前元素，直接压入栈
        else if (a[b.top()] > a[i])
        {
            b.push(i);
        }
        // 如果栈顶元素小于当前元素
        else
        {
            // 弹出栈顶元素，直到栈顶元素大于当前元素
            while (!b.empty() && a[b.top()] < a[i])
            {
                f[b.top()] = i;
                b.pop();
            }
            // 将当前索引压入栈
            b.push(i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << (f[i]==0?0:f[i]+1) << " ";
    }
    return 0;
}