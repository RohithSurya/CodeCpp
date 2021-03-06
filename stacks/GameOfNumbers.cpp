/**
 * @author: Podugu Rohith Surya
 * @link: https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/a-game-of-numbers-1-5d3a8cb3/
 * @desc: Write something about problem
 * Input:
 * Output:
 **/
#include <bits/stdc++.h>
using namespace std;

#define gc getchar_unlocked
#define fo(i, n) for (__typeof(n) i = 0; i < n; i++)
#define Fo(i, k, n) for (__typeof(n) i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

int mpow(int base, int exp);
void ipgraph(int n, int m);
void dfs(int u, int par);

const int mod = 1'000'000'007;
const int N = 3e5, M = N;
int greaterThan[N], lesserThan[N];

vi g[N];
int a[N];
int n,m;

int findJustGreaterIndex(int index) {
  Fo(i, index + 1, n + 1) {
    if (a[index] < a[i])
      return i;
  }
  return -1;
}

int findJustLesserIndex(int index) {
  Fo(i, index + 1, n + 1) {
    if (a[index] > a[i])
      return i;
  }
  return -1;
}

void solve() {
  si(n);
  Fo(i, 1, n + 1) si(a[i]);
  stack<int> s1, s2;
  Fo(i,n,0) {
    while(!s1.empty() && a[s1.top()]<=a[i]) s1.pop();
    greaterThan[i] = s1.empty()?-1:s1.top();
    s1.push(i);
  }
  // Fo(i,1,n+1) if(greaterThan[i]==-1) cout<<-1<<" "; else cout<<a[greaterThan[i]]<<" ";
  // cout<<endl;
  Fo(i,n,0) {
    while(!s2.empty() && a[s2.top()]>=a[i]) s2.pop();
    lesserThan[i] = s2.empty()?-1:s2.top();
    s2.push(i);
  }

  // Fo(i,1,n+1) if(lesserThan[i]==-1) cout<<-1<<" "; else cout<<a[lesserThan[i]]<<" ";
  // cout<<endl;
  Fo(i,1,n+1) if(!(greaterThan[i]==-1) && !(lesserThan[greaterThan[i]]==-1)) cout<<a[lesserThan[greaterThan[i]]]<<" ";
  else cout<<-1<<" ";

}



int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
}

int mpow(int base, int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1)
      result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}

void ipgraph(int n, int m) {
  int i, u, v;
  while (m--) {
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }
}

void dfs(int u, int par) {
  for (int v : g[u]) {
    if (v == par)
      continue;
    dfs(v, u);
  }
}