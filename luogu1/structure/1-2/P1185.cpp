#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

char canvas[2000][2000]; // 画布
bool removed[12][1025];  // 节点是否被删除
int node_x[12][1025], node_y[12], branch_len[12];
int m, n;

// 递归标记删除
void mark_removed(int r, int c)
{
    if (r > m)
        return;
    removed[r][c] = true;
    mark_removed(r + 1, c * 2 - 1); // 删除左子树
    mark_removed(r + 1, c * 2);     // 删除右子树
}

int main()
{
    cin >> m >> n;
    while (n--)
    {
        int r, c;
        cin >> r >> c;
        mark_removed(r, c);
    }

    // 1. 初始化画布
    for (int i = 0; i < 2000; ++i)
        for (int j = 0; j < 2000; ++j)
            canvas[i][j] = ' ';

    // 2. 预计算分支长度
    if (m >= 2)
        branch_len[m - 1] = 1;
    if (m >= 3)
        branch_len[m - 2] = 2;
    for (int i = m - 3; i >= 1; --i)
        branch_len[i] = branch_len[i + 1] * 2 + 1;

    // 3. 计算坐标
    // 第m层横坐标
    node_x[m][1] = 1;
    for (int j = 2; j <= (1 << (m - 1)); ++j)
    {
        node_x[m][j] = node_x[m][j - 1] + (j % 2 == 0 ? 4 : 2);
    }
    // 计算各层纵坐标及上层横坐标
    node_y[1] = 1;
    for (int i = 1; i < m; ++i)
        node_y[i + 1] = node_y[i] + branch_len[i] + 1;
    for (int i = m - 1; i >= 1; --i)
    {
        for (int j = 1; j <= (1 << (i - 1)); ++j)
        {
            node_x[i][j] = (node_x[i + 1][2 * j - 1] + node_x[i + 1][2 * j]) / 2;
        }
    }

    // 4. 绘图
    int total_h = node_y[m];
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= (1 << (i - 1)); ++j)
        {
            if (removed[i][j])
                continue;
            int r = node_y[i], c = node_x[i][j];
            canvas[r][c] = 'o';
            if (i < m)
            {
                if (!removed[i + 1][2 * j - 1]) // 左分支
                    for (int k = 1; k <= branch_len[i]; ++k)
                        canvas[r + k][c - k] = '/';
                if (!removed[i + 1][2 * j]) // 右分支
                    for (int k = 1; k <= branch_len[i]; ++k)
                        canvas[r + k][c + k] = '\\';
            }
        }
    }

    // 5. 输出（注意去除行末空格）
    for (int i = 1; i <= total_h; ++i)
    {
        int last = 1999;
        while (last >= 1 && canvas[i][last] == ' ')
            last--;
        for (int j = 1; j <= last; ++j)
            cout << canvas[i][j];
        cout << endl;
    }

    return 0;
}