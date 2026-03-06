#include <bits/stdc++.h>
using namespace std;
struct s{
    int a, b, c;
    int id;
    int z;
};
s stu[505];
bool cmp(s a,s b)
{
    if(a.z!=b.z)
        return a.z > b.z;
    if(a.a!=b.a)
        return a.a > b.a;
    if(a.id!=b.id)
        return a.id < b.id;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        stu[i].id = i;
        cin >> stu[i].a >> stu[i].b >> stu[i].c;
        stu[i].z = stu[i].a + stu[i].b + stu[i].c;
    }
    sort(stu + 1, stu + n + 1, cmp);
    for (int i = 1; i<=5;i++)
    {
        cout << stu[i].id << " " << stu[i].z<<endl;
    }
        return 0;
}