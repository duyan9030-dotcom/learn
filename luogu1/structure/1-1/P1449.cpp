#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    stack<long long> stacks;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '.' || s[i] == '@')
            continue;
        if (s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*')
        {
            long long a = 0;
            long long b = stacks.top();
            stacks.pop();
            long long c = stacks.top();
            stacks.pop();
            if (s[i] == '+')
                a = c + b;
            else if (s[i] == '-')
                a = c - b;
            else if (s[i] == '*')
                a = c * b;
            else if (s[i] == '/')
                a = c / b;
            stacks.push(a);
            
            continue;
        }
        long long a = 0;
        while (s[i] >= '0' && s[i] <= '9')
        {
            a = a * 10 + s[i++] - '0';
        }
        stacks.push(a);
    }
    cout << stacks.top();
}