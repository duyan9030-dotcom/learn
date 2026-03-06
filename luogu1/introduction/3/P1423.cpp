#include <iostream>
using namespace std;
int main()
{
    double s;
    cin >> s;
    double l=0;//游过的距离
    double b=2;
    int n=0;//步数
    while(l<s)
    {
        l+=b;
        b*=0.98;
        n++;
    }
    cout << n << endl;
    return 0;
}

