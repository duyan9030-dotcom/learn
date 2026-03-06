#include <bits/stdc++.h>
using namespace std;
vector<int> zhishu;
vector<vector<int>> ge;
bool yes(int a)
{
    for (int i = 2; i * i <= a; i++)
        if (a % i == 0)
            return false;
    return true;
}
void zhi()
{
    for (int i = 2; i < 10000; i++)
        if (yes(i))
            zhishu.push_back(i);
}
void yn(int a)
{
    for (int i = 0; zhishu[i] < a;i++)
        for (int j = 0; zhishu[j] < a;j++)
            if(zhishu[i]+zhishu[j]==a)
            {
                ge.push_back({a, zhishu[i], zhishu[j]});
                return;
            }
}
int main()
{
    int N;
    cin >> N;
    zhi();
    for (int i = 4; i <= N; i += 2)
        yn(i);
    for (int i = 0; i < ge.size();i++)
        cout << ge[i][0] <<"="<< ge[i][1] <<"+"<< ge[i][2]<<endl;
    return 0;
}