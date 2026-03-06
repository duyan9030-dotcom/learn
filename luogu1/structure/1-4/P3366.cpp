// 最小生成树

// 并查集
// #include <bits/stdc++.h>
// using namespace std;
// Kruskal
// struct node
// {
//     int f, t;
//     int w;
// };
// int father[5005];
// void build(int n)
// {
//     for (int i = 1; i <= n; i++)
//         father[i] = i;
// }
// int find(int a)
// {
//     if (a != father[a])
//         father[a] = find(father[a]);
//     return father[a];
// }
// void unio(int a, int b)
// {
//     father[find(a)] = father[b];
// }
// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     build(n);
//     vector<node> b(m);
//     for (int i = 0; i < m; i++)
//         cin >> b[i].f >> b[i].t >> b[i].w;
//     sort(b.begin(), b.end(), [](node a, node b)
//          { return a.w < b.w; });
//     int sum = 0, bsum = 0;
//     for (int i = 0; i < m && bsum < n - 1; i++)
//     {
//         if (find(b[i].f) != find(b[i].t))
//         {
//             unio(b[i].f, b[i].t);
//             sum += b[i].w;
//             bsum++;
//         }
//     }
//     if (bsum == n - 1)
//         cout << sum;
//     else
//         cout << "orz";
// }
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

// 边的结构体
// u, v: 节点编号 (在这个Prim实现中，我们只关心 v 和 w)
// w: 边的权重
struct Edge
{
    int v; // 目标节点 (next node)
    int w; // 权重 (cost)
};

// 自定义比较器：Min-Heap (最小权重优先)
// std::priority_queue 默认是 Max-Heap，使用 std::greater<T> 来实现 Min-Heap
// 注意：对于 std::pair 或 int[] 结构，需要自定义比较逻辑。
// 对于我们定义的 Edge 结构，我们可以使用 std::greater 配合重载的 operator> 或自定义仿函数。
// 为了简洁和直接匹配 Java 的 (a, b) -> a[1] - b[1] 逻辑，我们使用结构体和仿函数。
struct CompareEdge
{
    // 核心规则：如果 a 的优先级低于 b，返回 true。
    // 在 Min-Heap 中，权重 w 越大，优先级越低。
    bool operator()(const Edge &a, const Edge &b) const
    {
        return a.w > b.w; // w 越大，优先级越低，排在后面
    }
};

int main()
{
    // 提高输入输出效率
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    // 邻接表：graph[u] 存储所有从 u 出发的边 (Edge)
    // 节点编号从 1 到 n，所以 vector 大小为 n + 1
    vector<vector<Edge>> graph(n + 1);

    // 读取 m 条边
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        // 无向图：添加双向边
        // Java 代码中 int[] 对应这里的 Edge
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    // 优先队列 (Min-Heap)
    // std::priority_queue<数据类型, 容器类型, 比较器类型>
    priority_queue<Edge, vector<Edge>, CompareEdge> heap;
    int start_node = 1;

    // 2. 将起始节点连接的所有边放入队列
    for (const auto &edge : graph[start_node])
    {
        heap.push(edge);
    }

    // 已发现/已加入 MST 的节点集合 (set)
    vector<bool> set(n + 1, false);

    set[start_node] = true;
    int nodeCnt = 1;   // 已加入 MST 的节点计数
    long long ans = 0; // MST 的总权重，使用 long long 以防溢出

    // 3. 循环直到找到所有节点或队列为空
    while (!heap.empty())
    {
        Edge edge = heap.top();
        heap.pop();

        int next_node = edge.v;
        int cost = edge.w;
        // 如果 next_node 已经被加入 MST，则跳过
        if (set[next_node])
            continue;
        // 4. 找到未访问的最小边
        nodeCnt++;
        set[next_node] = true;
        ans += cost;
        if (nodeCnt == n)
            break;

        // 5. 将新加入节点的所有邻接边加入队列
        for (const auto &next_edge : graph[next_node])
        {
            // 优化：只加入连接到未访问节点的边 (非必须，但效率更高)
            if (!set[next_edge.v])
            {
                heap.push(next_edge);
            }
        }
    }
    if (nodeCnt == n)
        cout << ans << endl;
    else
        cout << "orz" << endl;
    return 0;
}