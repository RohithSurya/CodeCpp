/**
 * @author: Podugu Rohith Surya
 * @link: https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/algorithm/monk-learning-graph-3/
 * @desc: Sort according to given condition
 * Input:
 * Output:
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
vector<pair<int, int>> adj[N];
int val[N];
int n, m;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("/mnt/c/Users/prsur/projects/helloworld/input.txt", "r", stdin);
  freopen("/mnt/c/Users/prsur/projects/helloworld/output.txt", "w", stdout);
#endif
  int u, v;
  int k;
  cin >> n >> m >> k;
  REP(i, 1, n + 1, 1) { cin >> val[i]; }
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    adj[u].push_back({-val[v], -v});
    adj[v].push_back({-val[u], -u});
  }
  REP(i, 1, n + 1, 1) {
    if (k <= adj[i].size()) {
        //Sort the graph upto K
      partial_sort(adj[i].begin(), adj[i].begin() + k, adj[i].end());
      cout << -adj[i][k-1].second << endl;
    } else {
      cout << -1 << endl;
    }
  }
}