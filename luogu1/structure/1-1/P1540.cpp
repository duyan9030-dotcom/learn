#include <bits/stdc++.h>
using namespace std;
bool f(queue<int> q,int x)
{
    while(!q.empty())
    {
        if(x==q.front())
            return true;
        q.pop();
    }
    return false;
}
int main()
{
    int m, n, sum = 0;
    cin >> m >> n;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (!f(q, x))//内存里没找到了就需要查词典
        {
            if(q.size()==m)
                q.pop();
            q.push(x);
            sum++;
        }
    }
    cout << sum;
}