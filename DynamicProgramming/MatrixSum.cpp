/**
 * @author: Podugu Rohith Surya
 * @link: hacker earth
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
const int N = 1e3 + 5;  // Change according to needs
int n, m;
ll ma[N][N];
ll s[N][N];
int q;
int main() {
  int x, y;
#ifndef ONLINE_JUDGE
  freopen("/mnt/c/Users/prsur/projects/helloworld/input.txt", "r", stdin);
  freopen("/mnt/c/Users/prsur/projects/helloworld/output.txt", "w", stdout);
#endif
  cin >> n >> m;
  REP(i, 1, n + 1, 1) {
    REP(j, 1, m + 1, 1) {
      cin >> ma[i][j];
      s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + ma[i][j];
    }
  }
  cin >> q;
  while (q--) {
    cin >> x >> y;
    cout << s[x][y];
  }
}