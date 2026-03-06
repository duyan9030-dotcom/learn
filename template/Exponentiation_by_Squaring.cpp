#include <bits/stdc++.h>
using namespace std;

// 快速幂计算函数：计算 (x^n) % mod
int power(long long x, long long n, int mod)
{
    long long ans = 1; // 结果初始化为 1
    while (n > 0)
    { // 当指数 n 大于 0 时，继续计算
        if (n & 1)
        {                          // 如果当前指数 n 的最低位为 1（即 n 是奇数）
            ans = (ans * x) % mod; // 将当前的 x 乘入结果，并对 mod 取模
        }
        x = (x * x) % mod; // 将 x 平方，并对 mod 取模，相当于加倍指数
        n >>= 1;           // 将 n 右移一位，相当于指数除以 2
    }
    return ans; // 返回最终的结果
}

int main()
{
    // 测试代码
    long long x, n, mod;

    // 输入 base x，exponent n 和 modulus mod
    cout << "Enter base x, exponent n, and modulus mod: ";
    cin >> x >> n >> mod;

    // 调用 power 函数计算结果
    cout << "Result of " << x << "^" << n << " % " << mod << " = " << power(x, n, mod) << endl;

    return 0;
}
