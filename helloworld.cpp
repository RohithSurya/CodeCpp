/**
 * @author: Podugu Rohith Surya
 * @link: link
 * @desc: Write something about problem
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
vector<int> radj[N];
int n, m;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("/mnt/c/Users/prsur/projects/helloworld/input.txt", "r", stdin);
  freopen("/mnt/c/Users/prsur/projects/helloworld/output.txt", "w", stdout);
#endif
  int u, v, cnt, rcnt;
  ll w;
  cnt=rcnt=0;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> w;
    adj[u].push_back(v);
    radj[v].push_back(u);
  }
  REP(i,1,n+1,1) {
      if(adj[i].size()==0)
        cnt++;
  }
  
    REP(i,1,n+1,1) {
      if(radj[i].size()==0)
        rcnt++;
  }
  if(cnt>rcnt) cout<<cnt;
  else cout<<rcnt;
}