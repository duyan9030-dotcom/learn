#include <bits/stdc++.h>
using namespace std;
int x[5][5] = {{2, 0, 1, 1, 0},
               {1, 2, 0, 1, 0},
               {0, 1, 2, 0, 1},
               {0, 0, 1, 2, 1},
               {1, 1, 0, 0, 2}};
// 平2输0赢1
int main()
{
    int n, na, nb;
    cin >> n >> na >> nb;
    vector<int> A(na), B(nb);
    for (int i = 0; i < na; i++)
        cin >> A[i];
    for (int i = 0; i < nb; i++)
        cin >> B[i];
    int i = 0, j = 0;
    int a = 0, b = 0;
    for (int k = 0; k < n; k++)
    {
        if(x[A[i]][B[j]]==1)
            a++,i++,j++;
        else if (x[A[i]][B[j]] == 0)
            b++,i++,j++;
        else if (x[A[i]][B[j]] == 2)
            i++, j++;
        if(i>=na)
            i %= na;
        if(j>=nb)
            j %= nb;
    }
    cout << a << " " << b;
    return 0;
}