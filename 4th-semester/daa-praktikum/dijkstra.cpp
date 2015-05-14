/* Dijkstra can be used only if edges are non-negative.
*/
#include<iostream>
#include<vector>
#include<queue>
#include <functional>
#include <climits>

using namespace std;

// Infinity: INF + INF must not overflow
#define INF INT_MAX / 2
#define N 50001

int n, m;
vector<pair<int, int> > neighbours[N]; // Successors list: neighbours[from].push_back(to, edgeWeight)
int dist[N];
bool visited[N] = { 0 };
int parent[N];

int dijkstra(int s, int e)
{
	// By default, priority queue uses less comparator (max heap).
	// We need min heap => greater
	// By default, pairs are sorted by first coordinate, then by second.
	// => (dist[v], v)
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;	

	// ! If vertex indices are from {1, .. n}
	for (int i = 1; i <= n; i++)
	{
		dist[i] = INF; 
		parent[i] = -1;
	}
	dist[s] = 0;
	pq.push(pair<int, int>(0, s));

	while (!pq.empty())
	{
		int current = pq.top().second;
		pq.pop();
		if (visited[current]) // We push multiple pairs with the same vertex, but different distances. 
			continue;      // This vertex has already been popped (with shorter distance).
		if (current == e) 
			break;

		// Important: mark vertices as visited after popping, not before pushing.
		// We continue updating the best distance for pushed vertices.
		visited[current] = 1; 
		for (int i = 0; i < neighbours[current].size(); i++)
		{
			int next = neighbours[current][i].first;
			int edge = neighbours[current][i].second;
			if (!visited[next])
			{
				if (dist[next] > dist[current] + edge)
				{
					dist[next] = dist[current] + edge;
					parent[next] = current;
					pq.push(pair<int, int>(dist[next], next));
				}
			}
		}
		
	}
	if (dist[e] == INF)  // This vertex is unreachable from s
		return -1;
	return dist[e];
}

int main()
{
	int s, e;
	cin >> n >> m >> s >> e;

	int v1, v2, weight;
	for (int i = 0; i < m; i++)
	{
		cin >> v1 >> v2 >> weight;
		// Multiple edges from v1 to v2 are not a problem - all will be considered
		neighbours[v1].push_back(pair<int, int>(v2, weight));
		neighbours[v2].push_back(pair<int, int>(v1, weight));  // If undirected graph
	}

	cout<<dijkstra(s, e)<<endl;

	return 0;
}