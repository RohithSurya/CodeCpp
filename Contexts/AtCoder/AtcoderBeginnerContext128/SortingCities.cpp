/**
 * @author: Podugu Rohith Surya
 * @link: Link
 * @Working: Not working
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
pair<int, pair<string, int>> p[N];
bool comp(pair<int, pair<string, int>>& a, pair<int, pair<string, int>>& b) {
  string& s1 = a.s.f;
  string& s2 = b.s.f;
  int i1 = a.s.s;
  int i2 = b.s.s;
  if (s1.compare(s2) == 0) {
    return i1 > i2;
  } else {
    a.s < b.s;
  }
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("/mnt/c/Users/prsur/projects/helloworld/input.txt", "r", stdin);
  freopen("/mnt/c/Users/prsur/projects/helloworld/output.txt", "w", stdout);
#endif
  int n, score;
  string s1;
  cin >> n;
  REP(i, 0, n, 1) {
    cin >> s1 >> score;
    p[i] = {i + 1, {s1, score}};
  }
  sort(p, p + n, comp);
  REP(i, 0, n, 1) { cout << p[i].f << endl; }
}