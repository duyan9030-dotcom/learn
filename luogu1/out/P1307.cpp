#include <iostream>
using namespace std;
int main()
{
    int  N=0;
    cin >> N;
    int  x=0;
    while(N!=0)
    {
        x = x * 10 + N % 10;
        N /= 10;
    }
    cout<<x;
    return 0;
}
