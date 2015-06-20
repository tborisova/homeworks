#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <deque>
#include <queue>
#include <cstring>
using namespace std;

#define MAXN 200010
vector<int> ne[MAXN];
bool visited[MAXN];
deque<int> topo;
int time_in[MAXN];
int dist[MAXN];

void dfs(int cur)
{
    visited[cur] = 1;
    int nei;
    for(int i = 0; i < ne[cur].size(); ++i)
    {
        nei = ne[cur][i];
        if(!visited[nei])
        {
            dfs(nei);
        }
    }
    topo.push_front(cur);
}

void toposort(int n)
{
    for(int i = 0; i < n; ++i)
    {
        if(!visited[i])
        {
            dfs(i);
        }
    }
}

void findMinimal()
{
    int cur, nei;
    int n = topo.size()-1;
    for(int i = n; i >= 0; --i)
    {
        dist[i] = time_in[i];
    }

    for(int i = n; i >= 0; --i)
    {
        cur = topo[i];
        int m = 0;
        for(int j = 0; j < ne[cur].size(); ++j)
        {
            nei = ne[cur][j];
            m = max(m, dist[nei]);
        }
        dist[cur] = m+time_in[cur];
    }
}

int main()
{
    int n, t, m, task;

    scanf("%d", &n);

    for(int i = 0; i < n; ++i)
    {
        scanf("%d %d", &t, &m);
        time_in[i] = t;
        for(int j = 0; j < m; ++j)
        {
            scanf("%d", &task);
            ne[i].push_back(task);
        }
    }

    toposort(n);

    findMinimal();

    for(int i = 0; i < n; ++i)
    {
        printf("%d\n", dist[i]);
    }
    return 0;
}