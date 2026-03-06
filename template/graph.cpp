#include <bits/stdc++.h>
using namespace std;

// 链式前向星
int head[100005];  // 第i个点的头号边
int nexts[100005]; // 第i号边的下一个边
int to[100005];    // 第i号边要到哪去
int cnt = 1;       // 新增的边是第几号
void addedge(int u, int v)
{
    nexts[cnt] = head[u];
    to[cnt] = v;
    head[u] = cnt++;
}
void print()
{
    for (int i = 1; i <= cnt; i++)
        cout << head[i] << ' ';
    cout << endl;
    for (int i = 1; i <= cnt; i++)
        cout << nexts[i] << ' ';
    cout << endl;
    for (int i = 1; i <= cnt; i++)
        cout << to[i] << ' ';
    cout << endl;
}
#define maxn 1005
// 邻接表
struct node
{
    int d;
    vector<int> adj;
};
node graph3[maxn];
void addedgetable(int u, int v) // u->v
{
    graph3[u].adj.push_back(v);
}
// 邻接矩阵
int graph1[maxn][maxn]; // 有向图
int graph2[maxn][maxn]; // 无向图
void addedgematrix(int u, int v)
{
    graph1[u][v] = 1;
    // 有向图
    graph2[u][v] = 1;
    graph2[v][u] = 1;
    // 无向图
}
void build()
{
    memset(graph3, 0, sizeof(graph3));
    memset(head, 0, sizeof(head));
    memset(graph1, 0, sizeof(graph1));
    memset(graph2, 0, sizeof(graph2));
    int n, m; // n个点，m条边
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int f, t;
        cin >> f >> t;
        addedgetable(f, t);  // 邻接表
        addedgematrix(f, t); // 邻接矩阵
        addedge(f, t);       // 链式前向星建图
    }
}
int main()
{
    build();
    // print();
}
// https://leetcode.cn/problems/course-schedule-ii/description/
class Solution
{
public:
    struct node
    {
        int d;
        vector<int> adj;
    };
    int indegree[2005];
    node graph3[2005];
    void addedgetable(int u, int v) // u->v
    {
        graph3[u].adj.push_back(v);
        indegree[v]++;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        memset(indegree, 0, sizeof(indegree));
        memset(graph3, 0, sizeof(graph3));
        for (auto edge:prerequisites)
            addedgetable(edge[1],edge[0]);
        int queue[numCourses];
        int l = 0, r = 0;
        vector<int> s;
        for (int i = 0; i < numCourses;i++)
        {
            if(indegree[i]==0)
                queue[r++] = i;
        }
        int cnt = 0;
        while(l<r)
        {
            int cur = queue[l++];
            s.push_back(cur);
            cnt++;
            for (int i = 0; i < graph3[cur].adj.size();i++)
            {
                if (--indegree[graph3[cur].adj[i]] == 0)
                    queue[r++] = graph3[cur].adj[i];
            }
        }
        return cnt == numCourses ? s : vector<int>();
    }
};