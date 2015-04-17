#include<cstdio>
#include<vector>
using namespace std;

#define N 500
vector<int> neighbours[N];
bool visited[N];
int n, cycl = 0;

void dfs(int current, int parent)
{
	visited[current] = 1;
	for (int i = 0; i < neighbours[current].size(); i++)
	{	
		if(cycl) return;
		int next = neighbours[current][i];
		if(visited[next] && next != parent){
	        printf("Графът е цикличен! \n");
	        cycl = 1;
	        return;
		}else if (!visited[next] && next != parent)
			dfs(next, current);
	}
}

int dfsGraph()
{
	int componentsCount = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			dfs(i, - 1);
			if(cycl) break;
			componentsCount++;
		}
	}
  	if (0 == cycl) printf(" Графът е дърво (не съдържа цикли)!\n");
	return componentsCount;
}

int main()
{
	int m, i1, i2;
	scanf("%d%d", &n, &m);
	for (int j = 0; j < m; j++)
	{
		scanf("%d%d", &i1, &i2);
		neighbours[i1].push_back(i2);
		neighbours[i2].push_back(i1); // if undirected graph
	}

	printf("%d\n", dfsGraph());
	return 0;
}
