/**
 * @author: Podugu Rohith Surya
 * @link: link
 * @desc: Single source shortest path algorithm (Dijktras)
 * Input: n, m (n-vertices, m-edges) next m lines u, v, w (u->v, weight w);
 * Output: Single line containing shortest path cost;
 **/
#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define ll long long
using namespace std;
const int N = 1e6 + 5;
multiset<pair<ll, int>> ms;
vector<pair<ll, int>> adj[N];
ll dist[N];
bool visited[N];
vector<ll> shortestweights;

void initializel(int n) {
  for (int i = 0; i < n; i++) {
    dist[i] = INT_MAX;
    visited[i] = false;
  }
}

void dijktras() {
  ms.insert({0, 1});
  dist[1] = 0;
  while (!ms.empty()) {
    pair<ll, int> p = *ms.begin();
    ms.erase(ms.begin());
    int w = p.first;
    int u = p.second;
    if (visited[u]) continue;
    visited[u] = 1;
    cout << w << u << endl;
    shortestweights.pb(w);
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i].second;
      ll w1 = adj[u][i].first;
      if (dist[u] + w1 < dist[v]) {
        dist[v] = dist[u] + w1;
        ms.insert({dist[v], v});
      }
    }
  }
}
int main() {
  ll n, m, w;
  cin >> n >> m;
  ll x, y;
  for (ll i = 0; i < m; i++) {
    cin >> x >> y >> w;
    adj[x].pb({w, y});
  }
  initializel(n);
  dijktras();
  sort(shortestweights.begin(), shortestweights.end());
  for (int i = 0; i < shortestweights.size(); i++) {
    cout << shortestweights[i] << " ";
  }
}