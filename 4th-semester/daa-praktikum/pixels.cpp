#include<iostream>
#include<vector>
#include<queue>
#include <functional>
#include <climits>

using namespace std;

#define INF -1
#define N 1001
#define M 1001

struct point {
    int x, y, dist;

    point(int _x = 0, int _y = 0, int _dist = 0) {
        x = _x;
        y = _y;
        dist = _dist;
    }

    bool operator==(const point& other) const {
        return x == other.x && y == other.y;
    }

    bool operator<(const point& other) const {
        return dist < other.dist;
    }
};

int n, m;
long long a[N][M];
long long dist[N][M];
bool visited[N][M] = { 0 };

int dijkstra(point s, point e)
{
  priority_queue<pair<int, point>, vector<pair<int, point> >, less<pair<int, point> > > pq;

  for (int i = 0; i < n; i++)
    for (int j = 0; i < m; i++)
      dist[i][j] = -1;

  dist[s.x][s.y] = s.dist;
  pq.push(pair<int, point>(0, s));

  while (!pq.empty())
  {
    point current = pq.top().second;
    pq.pop();
    if (visited[current.x][current.y])
      continue;      
    if (current == e){
      break;
    }

    visited[current.x][current.y] = 1;
    int ky[3] = {-1, 0, 1};

    for (int i = 0; i < 3; i++)
    {
      int next_x = current.x + 1;
      int next_y = current.y + ky[i];

      if(next_x >= 0 && next_x < n && next_y >= 0 && next_y < m){
        long long edge = a[next_x][next_y];
        if (!visited[next_x][next_y])
        {
          if (dist[next_x][next_y] < dist[current.x][current.y] + edge)
          {
          
            cout << "djdjd" << endl;
            cout << next_x << " " << next_y << " " << edge << endl;
            dist[next_x][next_y] = dist[current.x][current.y] + edge;
            pq.push(pair<int, point>(dist[next_x][next_y], point(next_x, next_y, dist[next_x][next_y])));
          }
        }
      }
    }

  }
  if (dist[e.x][e.y] == INF)
    return -1;
  return dist[e.x][e.y];
}

int main()
{
  int s, e;
  cin >> n >> m;// >> s >> e; // tursim put ot s do e


  for (int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cin >> a[i][j];
  

  cout << dijkstra(point(0, 0, a[0][0]), point(n-1, m-1, a[n-1][m-1])) << endl;

  return 0;
}