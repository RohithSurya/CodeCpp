/**
 * @author: Podugu Rohith Surya
 * @link: https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/tutorial/
 * @desc: Number of nodes which cannot be reached from a given place
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
vector<int> adj[N];
int visited[N];
int n, m;
void dfs(int i) {
  visited[i] = true;
  for (auto &k : adj[i]) {
    if (!visited[k]) {
      dfs(k);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  REP(i, 1, n + 1, 1) visited[i] = false;
  int u, v;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int head;
  cin >> head;
  dfs(head);
  int cantReach = 0;
  REP(i, 1, n + 1, 1) {
    if (visited[i] != 1) cantReach++;
  }
  cout << cantReach;
}