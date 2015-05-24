#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <climits>
using namespace std;

#define MAXN 100
#define INF INT_MAX/2
vector<pair<int, int> > neighbours[MAXN];
char words[MAXN][128];
int n;
bool visited[MAXN];
int dist[MAXN];
int parent[MAXN];

struct Compare{
  bool operator() (pair<int, int> pair1, pair<int,int> pair2){
    if(pair1.first > pair2.first){
      return true;
    }else if(pair1.first == pair2.first){
      // cout << words[pair1.second] << " " << words[pair2.second] << endl;
      if(strcmp(words[pair1.second], words[pair2.second]) > 0){
        return true;
      }
    }

    return false;
  }
};

// Find the MST with root vertex s
void prim(int s)
{
  // By default, priority queue uses less comparator (max heap).
  // We need min heap => greater
  // By default, pairs are sorted by first coordinate, then by second.
  // => (dist[v], v)
  priority_queue<pair<int, int>, vector<pair<int, int> >, Compare > pq;

  // ! If vertex indexes are from {1, .. n}
  for (int i = 0; i < n; i++)
  {
    dist[i] = INF;
    parent[i] = -1;
  }
  dist[s] = 0;
  parent[s] = s;
  bool first = true;
  pq.push(pair<int, int>(0, s));
  int verticesCount = 0;

  while (!pq.empty())
  {
    int current = pq.top().second;
    pq.pop();
    if (visited[current]) // We push multiple pairs with the same vertex, but different distances. 
      continue;      // This vertex has already been popped (with shorter distance).

    // Important: mark vertices as visited after popping, not before pushing.
    // We continue updating the best distance for pushed vertices.
    visited[current] = 1;
    verticesCount++;
    if(!first){
      cout << words[parent[current]] <<" "<< words[current] << endl;
    }
    if (verticesCount == n)
      break;

    for (int i = 0; i < neighbours[current].size(); i++)
    {
      first = false;
      int next = neighbours[current][i].first;
      int edge = neighbours[current][i].second;
      // cout << " current is " << words[current] << " " << words[next] << " " << edge << endl;
      if (!visited[next])
      {
        if (dist[next] > edge)
        {
          dist[next] = edge;
          parent[next] = current;
          pq.push(pair<int, int>(dist[next], next));
        }
      }
    }

  }
}

int main(){

  scanf("%d", &n);
  int minw = 0;
  cin >> words[0];

  for(int i = 1; i < n; i++){
    cin >> words[i];
    if(strcmp(words[minw], words[i]) > 0) minw = i;
  }

  for(int i = 0; i < n - 1; i++){
    for(int j = i; j < n; j++){
      int dist = 0;
      if(i != j){
        int min_dist = min(strlen(words[i]), strlen(words[j]));
        for(int k = 0; k < min_dist; k++){
          dist += abs(words[i][k] - words[j][k]);
        }
      }
      neighbours[i].push_back(pair<int, int>(j, dist));
      neighbours[j].push_back(pair<int, int>(i, dist));
    }
  }

  prim(minw);
}