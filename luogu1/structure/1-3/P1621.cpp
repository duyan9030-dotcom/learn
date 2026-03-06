#include <bits/stdc++.h>
using namespace std;
int father[100005];
bool primes[100005] = {true};
int a, b, p;
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b); // 最大公因数
}
bool ok(int a) // 判断质数
{
    for (int i = 2; i <= sqrt(a); i++)
        if (a % i == 0)
            return false;
    return true;
}
void prime()
{
    memset(primes, true, sizeof(primes));
    for (int i = 2; i <= b; i++)
    {
        if (!primes[i])
            continue;
        if (ok(i)) // 如果是质数,他的所有倍数都不是质数
        {
            for (int j = 2; i * j <= b; j++)
                primes[i * j] = false;
        }
        else
        {
            primes[i] = false;
        }
    }
}
int find(int a)
{
    if (a != father[a])
        father[a] = find(father[a]);
    return father[a];
}
void unio(int x, int y)
{
    father[find(x)] = find(y);
}
void init(int a, int b)
{
    for (int i = a; i <= b; i++)
        father[i] = i;
}
int main()
{

    cin >> a >> b >> p;
    init(a, b);
    prime();                     // 遍历b以内的所有质数，如果
    for (int i = p; i <= b; i++) // 遍历可能的质因数
    {
        if (primes[i]) // 是质数才合并
        {
            int f = -1;
            for (int j = (a + i - 1) / i * i; j <= b; j+=i)
            {
                if (f == -1)
                    f = j;
                else
                    unio(f, j);
            }
        }
    }
    int sum = 0;
    for (int i = a; i <= b; i++)
        if (father[i] == i)
            sum++;
    cout << sum;
}