#include <bits/stdc++.h>
using namespace std;
int main()
{
    int w;
    cin >> w;
    double j=0;
    if(w<=150&&j>=0)
    {
        j = w * 0.4463;
    }
    if(w>=151&&w<=400)
    {
        j = 150 * 0.4463 + (w - 150) * 0.4663;
    }
    if(w>=401)
    {
        j = 150*0.4463+250*0.4663+(w-400)*0.5663;
    }
    printf("%.1lf", j);
    return 0;
}