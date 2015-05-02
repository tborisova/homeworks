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

int n, m,k, counter = 0;
vector<pair<int, int> > neighbours[N]; // Successors list: neighbours[from].push_back(to, edgeWeight)
int dist[N];
bool visited[N] = { 0 };
int parent[N];

int dijkstra(int s)
{
  // By default, priority queue uses less comparator (max heap).
  // We need min heap => greater
  // By default, pairs are sorted by first coordinate, then by second.
  // => (dist[v], v)
  priority_queue<pair<int, int> > pq;  

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
    int current_dis = pq.top().first;
    pq.pop();
    cout << "parent " << current_dis << endl;
    // counter += current_dis;
    if (visited[current]) // We push multiple pairs with the same vertex, but different distances. 
      continue;      // This vertex has already been popped (with shorter distance).
    // if (current == e) 
    //   break;

    // Important: mark vertices as visited after popping, not before pushing.
    // We continue updating the best distance for pushed vertices.
    visited[current] = 1; 
    for (int i = 0; i < neighbours[current].size(); i++)
    {

      int next = neighbours[current][i].first;
      int edge = neighbours[current][i].second;
      if (!visited[next])
      {
        if (current_dis < edge){
          cout << "curret " << current << "next  " << next << " edge " << edge << endl; 
          pq.push(pair<int, int>(current_dis + edge, next));
        }
      }
    }
    
  }
  // if (dist[e] == INF)  // This vertex is unreachable from s
  //   return -1;
  return 1;
}

int main()
{
  int num;
  // scanf("%d %d", &n, )
  cin >> n >> k;
  // int s, e;
  // cin >> n >> m >> s >> e;

  // int v1, v2, weight;
  // for (int i = 0; i < m; i++)
  // {
  //   cin >> v1 >> v2 >> weight;
  //   // Multiple edges from v1 to v2 are not a problem - all will be considered
  //   neighbours[v1].push_back(pair<int, int>(v2, weight));
  //   neighbours[v2].push_back(pair<int, int>(v1, weight));  // If undirected graph
  // }

  for(int i = 0 ; i < n ; i++){
    for(int j = 0; j < n; j++){
      // scanf("%d", &num);
      cin >> num;
      neighbours[i].push_back(pair<int, int>(j, num));
      neighbours[j].push_back(pair<int, int>(i, num));

    }
  }

  dijkstra(0);
  cout <<"--------" << endl;
  cout<<counter<<endl;

  return 0;
}