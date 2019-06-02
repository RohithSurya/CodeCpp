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
const int N = 1e2 + 5;  // Change according to needs
int m[N][2];
const int RED = 0;
const int BLUE = 1;
int nb[N][N][N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
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
  REP(r,0,101,1) {
    REP(b,0,101,1) {
      nb[0][r][b] = 0;
    }
  }
  REP(k,1,rows+1,1) {
    REP(r,0,101,1) {
      REP(b,0,101,1) {
        if(r<m[k][RED] || b<m[k][BLUE]) {
          nb[k][r][b]=nb[k-1][r][b];
        } else
        {
          nb[k][r][b]=max(nb[k-1][r][b], 1+nb[k-1][r-m[k][RED]][b-m[k][BLUE]]);
        }
        
      }
    }
  }

  while (q--) {
    cin >> x >> y;
    cout << nb[rows][x][y] << endl;
  }
}