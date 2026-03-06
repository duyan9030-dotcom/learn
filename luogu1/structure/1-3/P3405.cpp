#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int sum = 0;
    cin >> n;
    string a, b;
    unordered_map<string, int> cs;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b; // 需要判断a的前两个字母组成的字符串是否在之前的b所构成的集合，并且b在a前两个字符所构成的集合
        string s = a.substr(0, 2);
        if (s != b)
        {
            if(cs[b+s]>0)
                sum += cs[b+s];
            cs[s + b]++;
        }
    }
    cout << sum;
}