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
vector<pair<int, ll>> adj[N];
int n, m;
int main()
{
    int u, v;
    ll w;
#ifndef ONLINE_JUDGE
    freopen("/mnt/c/Users/prsur/projects/helloworld/input.txt", "r", stdin);
    freopen("/mnt/c/Users/prsur/projects/helloworld/output.txt", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
}