/**
 * @author: Podugu Rohith Surya
 * @link: link
 * @desc: Multi stage graph problem;
 * Input: n,m n-vertices, m-edges, after this every line contains m edges u,v,w
 *u-from v-to w-weight; Output: Single line containing shortest path cost;
 **/
#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
typedef long long ll;
#define mset(A, a) memset(A, a, sizeof(A))
#define REP(i, a, b, k) for (__typeof(a) i = a; i < b; i += k)
using namespace std;
const int N = 1e5 + 5;
vector<pair<int, ll>> adj[N];
int n, m;
ll minPath[N];
ll shortestPath(int i) {
  if (minPath[i] != -1) {
    return minPath[i];
  }
  if (i == n - 1) return minPath[i] = 0;
  ll ans = LLONG_MAX;
  for (auto p : adj[i]) {
    int k = p.f;
    ll w = p.s;
    ans = min(ans, w + shortestPath(k));
  }
  return minPath[i] = ans;
}
int main() {
  int u, v;
  ll w;
#ifndef ONLINE_JUDGE
  freopen("/mnt/c/Users/prsur/projects/helloworld/input.txt", "r", stdin);
  freopen("/mnt/c/Users/prsur/projects/helloworld/output.txt", "w", stdout);
#endif
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
  }
  REP(i, 0, n, 1) { minPath[i] = -1; }
  cout << shortestPath(0);
}