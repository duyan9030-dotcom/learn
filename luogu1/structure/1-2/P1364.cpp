// #include <bits/stdc++.h>
// using namespace std;
// int dis[105][105]; // 任意两点间距离
// struct node
// {
//     int w;
//     int l, r;
//     int father;
// };
// node tree[105];
// int main()
// {
//     int n, w, u, v;
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> w >> u >> v;
//         tree[i].w = w;
//         tree[i].l = u;
//         tree[i].r = v;
//         tree[u].father = tree[v].father = i;
//     }
//     for (int i = 1; i <= n; i++) // i->j的距离
//         for (int j = 1; j <= n; j++)
//         {
//             if (i == j)
//                 continue;
//             if (dis[j][i] != 0)
//                 dis[i][j] = dis[j][i];
//             else
//                 dis[i][j] = dis[i][tree[j].father] + 1;
//         }
//     int ans = 1e9;
//     for (int i = 1; i <= n; i++)
//     {
//         int sum = 0;
//         for (int j = 1; j <= n; j++)
//             sum += tree[j].w * dis[j][i];
//         ans = min(ans, sum);
//     }
//     cout << ans;
// }
#include <bits/stdc++.h>
using namespace std;

// 使用 0x3f3f3f3f 表示无穷大，防止加法溢出
const int INF = 0x3f3f3f3f;
int dis[105][105];
int w[105]; // 存储每个节点的人口

int main()
{
    int n;
    cin >> n;

    // 1. 初始化距离矩阵
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                dis[i][j] = 0;
            else
                dis[i][j] = INF;
        }
    }

    // 2. 读入数据并建立邻接关系（距离为 1）
    for (int i = 1; i <= n; i++)
    {
        int l, r;
        cin >> w[i] >> l >> r;
        if (l != 0)
        {
            dis[i][l] = dis[l][i] = 1;
        }
        if (r != 0)
        {
            dis[i][r] = dis[r][i] = 1;
        }
    }

    // 3. Floyd 核心算法：三重循环
    // k 为中转点，i 为起点，j 为终点
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dis[i][k] + dis[k][j] < dis[i][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }

    // 4. 枚举医院建立的地点，计算最小总距离
    long long ans = 1e18; // 用更大范围存储答案
    for (int i = 1; i <= n; i++)
    { // 假设医院建在 i
        long long sum = 0;
        for (int j = 1; j <= n; j++)
        { // 统计其他所有点 j 到 i 的距离
            sum += (long long)w[j] * dis[i][j];
        }
        ans = min(ans, sum);
    }

    cout << ans << endl;
    return 0;
}