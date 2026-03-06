#include <iostream>
#include <string>
using namespace std;
#define max(a, b) (((a) > (b)) ? (a) : (b))
string add(string a, string b)
{
    int A[1000] = {0}, B[1000] = {0};
    for (int i = a.length() - 1; i >= 0; i--)
        A[a.length() - i - 1] = a[i] - '0';
    for (int i = b.length() - 1; i >= 0; i--)
        B[b.length() - i - 1] = b[i] - '0';
    for (int i = 0; i < max(a.length(), b.length()); i++)
    {
        A[i] += B[i];
        if(A[i]>=10)
        {
            A[i + 1] += A[i] / 10;
            A[i] %= 10;
        }
    }
    int head = 999;
    string c = "";
    while(A[head]==0)
        head--;
    for (; head >= 0;head--)
        c += '0' + A[head];
    return c;
}
int main()
{
    int n, m;
    cin >> n >> m;
    string a = "1", b = "1",c;
    for (int i = n+1; i < m; i++)
    {
        c = add(a, b);
        a = b;
        b = c;
    }
    cout << c;
}