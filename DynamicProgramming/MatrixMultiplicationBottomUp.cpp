/**
 * @author: Podugu Rohith Surya
 * @link: No link
 * @desc: Write something about problem
 * Input: No of matrices and after the dimensions of matrices
 * Output: Single integer denoting the least multiplications.
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
int p[N];
int n;
int m[N][N];
int main() {
  int ans;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  cin >> n;
  // Input the dimensions of matrix
  REP(i, 0, n + 1, 1) {
    // For matrix i dimensions = i-1 * i;
    cin >> p[i];
  }
  // For a single matrix cost of combining 0;
  REP(i, 1, n + 1, 1) { m[i][i] = 0; }
  // var l, corresponds to 1, 2, 3 distance subproblems
  REP(l, 1, n, 1) {
    // computing m[i,j]
    REP(i, 1, n - l + 1, 1) {
      // j in (i,j) initialization
      int j = i + l;
      int ans = INT_MAX;
      REP(k, i, j, 1) {
        ans = min(ans, m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]);
      }
      m[i][j] = ans;
    }
  }

  cout << m[1][n];
}