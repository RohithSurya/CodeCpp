/**
 * @author: Podugu Rohith Surya
 * @Done: Yes
 * @link:
 *https://www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/monk-visits-coderland-4/
 * @desc: Greedy Algorithms
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
int c[N], l[N];
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int q, n;
  ll min, tc, sum;
  cin >> q;
  while (q--) {
    cin >> n;
    // Get the petrol cost
    REP(i, 0, n, 1) { cin >> c[i]; }
    // Get the litres of petrol
    REP(i, 0, n, 1) { cin >> l[i]; }
    min = c[0];
    tc = 0;
    sum = l[0];
    REP(i, 1, n, 1) { 
      if (c[i] < min) {
        tc += sum * min;
        min = c[i];
        sum = l[i];
      } else {
        sum += l[i];
      }
    }
    tc += sum * min;
    cout << tc << endl;
  }
}