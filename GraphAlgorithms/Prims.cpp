/**
 * @author: Podugu Rohith Surya
 * @link: No link;
 * @desc: Single source shortest path algorithm Prims;
 * Input: n, m (n-vertices, m-edges) next m lines u, v, w (u->v, weight w);
 * Output: Single line containing Minimum spanning tree cost;
 **/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> PII;
const int N = 1e5 + 5;
vector<PII> adj[N];
bool visited[N] = {false};
ll prims() {
  ll mincost = 0;
  priority_queue<PII, vector<PII>, greater<PII>> pq;
  pq.push({0, 1});
  while (!pq.empty()) {
    auto t = pq.top();
    pq.pop();
    int vertex = t.second;
    if (visited[vertex] == true) continue;
    visited[vertex] = true;
    mincost += t.first;
    for (int i = 0; i < adj[vertex].size(); i++) {
      if (visited[adj[vertex][i].second] == false) pq.push(adj[vertex][i]);
    }
  }
  return mincost;
}

int main() {
  int n, m;
  cin >> n >> m;
  int x, y;
  ll weight;
  for (int i = 0; i < m; i++) {
    cin >> x >> y >> weight;
    adj[x].push_back({weight, y});
    adj[y].push_back({weight, x});
  }
  cout << prims();