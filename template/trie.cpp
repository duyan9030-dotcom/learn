// #include <bits/stdc++.h>
// using namespace std;
// class trienode
// {
// public:
//     int pass;
//     int end;
//     trienode *nexts[26] = {nullptr};
//     trienode()
//     {
//         pass = 0;
//         end = 0;
//     }
// };
// class trienode2
// {
// public:
//     int pass;
//     int end;
//     unordered_map<int, trienode2 *> nexts;
//     trienode2()
//     {
//         pass = 0;
//         end = 0;
//     }
//     ~trienode2()
//     {
//         for (auto &pair : nexts)
//         {
//             delete pair.second;
//             pair.second = nullptr;
//         }
//         nexts.clear();
//     }
// };
// trienode *root;
// trienode2 *root2;
// void trie()
// {
//     root = new trienode();
// }
// void insert(string word)
// {
//     trienode *node = root;
//     node->pass++;
//     for (int i = 0, path; i < word.size(); i++)
//     {
//         path = word[i] - 'a';
//         if (node->nexts[path] == nullptr)
//         {
//             node->nexts[path] = new trienode();
//         }
//         node = node->nexts[path];
//         node->pass++;
//     }
//     node->end++;
// }
// int search(string word)
// {
//     trienode *node = root;
//     for (int i = 0, path; i < word.size(); i++)
//     {
//         path = word[i] - 'a';
//         if (node->nexts[path] == nullptr)
//         {
//             return 0;
//         }
//         node = node->nexts[path];
//     }
//     return node->end;
// }
// int prefixnumber(string pre)
// {
//     trienode *node = root;
//     for (int i = 0, path; i < pre.size(); i++)
//     {
//         path = pre[i] - 'a';
//         if (node->nexts[path] == nullptr)
//         {
//             return 0;
//         }
//         node = node->nexts[path];
//     }
//     return node->pass;
// }
// void freenode(trienode *node)
// {
//     if (node == nullptr)
//         return;
//     for (int i = 0; i < 26; i++)
//     {
//         freenode(node->nexts[i]);
//         node->nexts[i] = nullptr;
//     }
//     delete node;
// }
// void erase(string word)
// {
//     if (prefixnumber(word) > 0)
//     {
//         trienode *node = root;
//         node->pass--;
//         for (int i = 0, path; i < word.size(); i++)
//         {
//             path = word[i] - 'a';
//             if (--node->nexts[path]->pass == 0)
//             {
//                 freenode(node->nexts[path]);
//                 node->nexts[path] = nullptr;
//                 return;
//             }
//             node = node->nexts[path];
//         }
//         node->end--;
//     }
// }
// void trie2()
// {
//     root2 = new trienode2;
// }
// void insert2(string word)
// {
//     trienode2 *node = root2;
//     node->pass++;
//     for (int i = 0, path; i < word.size(); i++)
//     {
//         char a = word[i];
//         if (node->nexts.find(a) == node->nexts.end())
//         {
//             node->nexts[a] = new trienode2();
//         }
//         node = node->nexts[a];
//         node->pass++;
//     }
//     node->end++;
// }
// int search2(string word)
// {
//     if (word.empty())
//         return 0;
//     trienode2 *node = root2;
//     for (int i = 0, path; i < word.size(); i++)
//     {
//         char a = word[i];
//         if (node->nexts.find(a) == node->nexts.end())
//         {
//             return 0;
//         }
//         node = node->nexts[a];
//     }
//     return node->end;
// }
// int prefixnumber2(string pre)
// {
//     if (pre.empty())
//         return 0;
//     trienode2 *node = root2;
//     for (int i = 0, path; i < pre.size(); i++)
//     {
//         char a = pre[i];
//         if (node->nexts.find(a) == node->nexts.end())
//         {
//             return 0;
//         }
//         node = node->nexts[a];
//     }
//     return node->pass;
// }
// // 更安全的删除：仅在单词确实存在时删除一次，并返回是否删除成功
// bool erase2(const string &word)
// {
//     if (root == nullptr)
//         return false;
//     if (search(word) == 0)
//         return false; // 单词不存在

//     // 记录经过的节点以便回退
//     vector<trienode *> nodes;
//     trienode *node = root;
//     nodes.push_back(node);
//     for (char ch : word)
//     {
//         int idx = ch - 'a';
//         if (idx < 0 || idx >= 26)
//             return false; // 非小写字母，不处理
//         node = node->nexts[idx];
//         nodes.push_back(node);
//     }

//     // 减少终结计数
//     trienode *last = nodes.back();
//     last->end--;

//     // 从尾到头递减 pass 并在需要时释放子树
//     for (int i = (int)word.size() - 1; i >= 0; --i)
//     {
//         trienode *cur = nodes[i + 1];
//         trienode *parent = nodes[i];
//         --cur->pass;
//         if (cur->pass == 0)
//         {
//             int idx = word[i] - 'a';
//             parent->nexts[idx] = nullptr;
//             freenode(cur);
//         }
//         else
//         {
//             // 如果当前节点仍被其他单词共享则停止回收
//             break;
//         }
//     }

//     // 根节点的 pass 也应减少（search 已确保存在）
//     root->pass--;
//     return true;
// }

// // 简单 main 用于测试 erase2 的行为
// int main()
// {
//     trie(); // 初始化根节点

//     insert("apple");
//     insert("apple");
//     insert("app");

//     cout << "search(apple)=" << search("apple") << " expected 2\n";
//     cout << "search(app)=" << search("app") << " expected 1\n";
//     cout << "prefixnumber(app)=" << prefixnumber("app") << " expected 3\n";

//     cout << "erase2(apple) -> " << (erase2("apple") ? "ok" : "fail") << "\n";
//     cout << "search(apple)=" << search("apple") << " expected 1\n";
//     cout << "prefixnumber(app)=" << prefixnumber("app") << " expected 2\n";

//     cout << "erase2(apple) -> " << (erase2("apple") ? "ok" : "fail") << "\n";
//     cout << "search(apple)=" << search("apple") << " expected 0\n";
//     cout << "prefixnumber(app)=" << prefixnumber("app") << " expected 1\n";

//     cout << "erase2(apple) -> " << (erase2("apple") ? "ok" : "fail") << " expected fail\n";

//     cout << "erase2(app) -> " << (erase2("app") ? "ok" : "fail") << "\n";
//     cout << "search(app)=" << search("app") << " expected 0\n";
//     cout << "prefixnumber(app)=" << prefixnumber("app") << " expected 0\n";

//     // 释放剩余节点
//     freenode(root);
//     root = nullptr;

//     return 0;
// }

// static
#include <bits/stdc++.h>
using namespace std;
#define maxn 1500001
int tree[maxn][26];
int endd[maxn]; // 有多少字符串以这个字符结尾
int pass[maxn]; // 有多少字符串经过这个节点
int cnt = 1;    // 当前最大的节点

void insert(string word)
{
    int cur = 1;
    pass[cur]++;
    for (int i = 0, path; i < word.size(); i++)
    {
        //从一开始判断这个节点是否有，如果有pass++，没有就新建一个节点
        path = word[i] - 'a';
        if (tree[cur][path] == 0)
            tree[cur][path] = ++cnt;
        cur = tree[cur][path];
        pass[cur]++;
    }
    endd[cur]++;
}
int search(string word)
{
    int cur = 1;
    for (int i = 0, path; i < word.size(); i++)
    {
        path = word[i] - 'a';
        if (tree[cur][path] == 0)
            return 0;
        cur = tree[cur][path];
    }
    return endd[cur];
}
int prefixnumber(string word)
{
    int cur = 1;
    // int ans = 0;
    for (int i = 0, path; i < word.size(); i++)
    {
        path = word[i] - 'a';
        if (tree[cur][path] == 0)
            break;
        // ans += endd[tree[cur][path]];
        cur = tree[cur][path];
    }
    return pass[cur];
    // return ans;
}
void erase(string word)
{
    if (search(word) > 0)
    {
        int cur = 1;
        for (int i = 0, path; i < word.size(); i++)
        {
            path = word[i] - 'a';
            // if (--pass[tree[cur][path]] == 0)
            // {
            //     tree[cur][path] = 0;
            //     return;
            // }
            cur = tree[cur][path];
        }
        endd[cur]--;
    }
}
void clear(int cnt)
{
    cnt = 1;
    memset(tree, 0, (cnt + 1) * 26);
    memset(tree, 0, cnt + 1);
    memset(tree, 0, cnt + 1);
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        insert(s);
    }
    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        cout << prefixnumber(s) << endl;
    }
}