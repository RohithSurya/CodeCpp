/**
 * @author: Podugu Rohith Surya
 * @link: https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/monk-and-graph-problem/
 * @desc: Monk and Graph problem
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
vector<pair<int, ll>> adj[N];
int n, m;
int parent[N];
int rnk[N];

void initialize() {
  for (int i = 1; i < n + 1; i++) {
    parent[i] = i;
    rnk[i] = 0;
  }
}

int findSet(int i) {
  if (i == parent[i])
    return i;
  else {
    parent[i] = findSet(parent[i]);
    return parent[i];
  }
}

bool setUnion(int i, int j) {
  int pi = findSet(i);
  int pj = findSet(j);
  if (pi == pj) {
    rnk[pi] += 1;
    return false;
  }
  if (rnk[pi] >= rnk[pj]) {
    rnk[pi] += rnk[pj] + 1;
    parent[pj] = pi;
  } else {
    parent[pi] = pj;
    rnk[pj] += rnk[pi] + 1;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int u, v;
  ll w;
  cin >> n >> m;
  initialize();
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    setUnion(u, v);
  }
  int maxComp = INT_MIN;
  REP(i, 1, n + 1, 1) {
    if (i == parent[i]) maxComp = max(maxComp, rnk[i]);
  }
  cout << maxComp;
}