#include <iostream>
using namespace std;
int h(int i,int x)
{
    int k=0;
    while(i!=0)
    {
        if(i%10==x)
            k++;
        i /= 10;
    }
    return k;
}
int main()
{
    int n, x;
    cin >> n;
    cin >> x;
    int c=0;
    for (int i = 1; i <= n;i++)
    {
        c += h(i, x);
    }
    cout << c;
    return 0;
}