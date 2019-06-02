/**
 * @author: Podugu Rohith Surya
 * @link: No Link
 * @desc: Kruskalls Minimum spanning tree algorithm.
 * Input: n, m (n-vertices, m-edges) next m lines u, v, w (u->v, weight w);
 * Output: Print the total cost of spanning tree;
 **/
#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mset(A, a) memset(A, a, sizeof(A))
#define REP(i, a, b, k) for (__typeof(a) i = a; i < b; i += k)
typedef long long ll;
const int N = 1e5 + 5;
pair<ll, pair<int, int>> p[N];
int parent[N];
int rnk[N];
int m;

void initialize(int n) {
  for (int i = 0; i < n; i++) {
    parent[i] = i;
    rnk[i] = 1;
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
  if (pi == pj) return false;
  if (rnk[pi] >= rnk[pj]) {
    rnk[pi] += rnk[pj];
    parent[pj] = pi;
  } else {
    parent[pi] = pj;
    rnk[pj] += rnk[pi];
  }
  return true;
}

ll kruskal() {
  ll mincost = 0;
  int x, y;
  sort(p, p + m);
  for (int i = 0; i < m; i++) {
    x = p[i].second.first;
    y = p[i].second.second;
    if (findSet(x) == findSet(y)) continue;
    setUnion(x, y);
    mincost += p[i].first;
  }
  return mincost;
}
int main() {
  int n;
  ll weight;
  int x, y;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> x >> y >> weight;
    p[i] = {weight, {x, y}};
  }
  cout << kruskal();
}