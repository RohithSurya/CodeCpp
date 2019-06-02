/**
 * @author: Podugu Rohith Surya
 * @link: Link
 * @desc: Write something about problem
 * Input:
 * Output:
 **/
#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mset(A, a) memset(A, a, sizeof(A))
#define REP(i, a, b, k) for (__typeof(a) i = a; i < b; i += k)
typedef long long ll;
using namespace std;
const int N = 1e4 + 5;  // Change according to needs
int ks[N][N];
int w[N];
int p[N];
int main() {
#ifndef ONLINE_JUDGE
  freopen("/mnt/c/Users/prsur/projects/helloworld/input.txt", "r", stdin);
  freopen("/mnt/c/Users/prsur/projects/helloworld/output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, wei;
  cin >> n >> wei;
  REP(i, 0, n, 1) { cin >> w[i]; }
  REP(i, 0, n, 1) { cin >> p[i]; }
  REP(i, 0, n + 1, 1) { ks[i][0] = 0; }
  REP(i, 0, wei + 1, 1) { ks[0][i] = 0; }
  REP(item, 1, n + 1, 1) {
    REP(weight, 1, wei + 1, 1) {
      if (w[item] > weight) {
        ks[item][weight] = ks[item - 1][weight];
      } else {
        ks[item][weight] =
            max(ks[item - 1][weight], ks[item - 1][weight - w[item]] + p[item]);
      }
    }
  }
  cout << ks[n][wei];
}