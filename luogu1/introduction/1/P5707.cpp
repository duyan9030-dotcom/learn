#include <bits/stdc++.h>
using namespace std;
double s,v;
int main()
{
    cin >> s >> v;
    int m = ceil(s / v) + 10;//s,v必须为浮点型，若为int则相除后结果为整数，向上取整仍为本身
    int t = 8 * 60 + 24 * 60 - m;
    if(t>=24*60)
        t -= 24 * 60;
    int b=t%60;//出发分
    int a = t / 60;//出发时
    if (a< 10)
    {
        if (b<10)
            printf("0%d:0%d", a,b);
        else
            printf("0%d:%d", a, b);
    }
    else
    {
        if (b<10)
            printf("%d:0%d", a, b);
        else
            printf("%d:%d", a, b);
    }
    return 0;
}
