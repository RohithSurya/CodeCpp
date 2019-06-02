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
const int N = 1e5 + 5;  // Change according to needs
int m[N][2];
const int RED = 0;
const int BLUE = 1;

int noOfBalls(int n, int r, int b) {
  if (n == 0) return 0;
  if (r < m[n][RED] || b < m[n][BLUE]) {
    return noOfBalls(n - 1, r, b);
  } else {
    return max(noOfBalls(n - 1, r, b),
               1 + noOfBalls(n - 1, r - m[n][RED], b - m[n][BLUE]));
  }
}
int main() {
  int rows;
#ifndef ONLINE_JUDGE
  freopen("/mnt/c/Users/prsur/projects/helloworld/input.txt", "r", stdin);
  freopen("/mnt/c/Users/prsur/projects/helloworld/output.txt", "w", stdout);
#endif
  cin >> rows;
  string st;
  REP(i, 1, rows + 1, 1) {
    cin >> st;
    int r = 0, b = 0;
    for (char c : st) {
      if (c == 'R')
        r++;
      else
        b++;
    }
    m[i][RED] = r;
    m[i][BLUE] = b;
  }
  //   REP(i, 1, rows + 1, 1) { cout << m[i][RED] << " " << m[i][BLUE] << endl;
  //   }
  int q, x, y;
  cin >> q;
  while (q--) {
    cin >> x >> y;
    cout << noOfBalls(rows, x, y) << endl;
  }
}