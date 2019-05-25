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
const int N = 1e3 + 5; //Change according to needs
int p[N];
int n;
int m[N][N];
int main()
{
    int ans;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n;
    REP(i, 0, n + 1, 1)
    {
        cin >> p[i];
    }
    REP(i, 1, n + 1, 1)
    {
        m[i][i] = 0;
    }
    REP(l, 1, n, 1)
    {
        REP(i, 1, n - l + 1, 1)
        {
            int j = i + l;
            int ans = INT_MAX;
            REP(k, i, j, 1)
            {
                ans = min(ans, m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]);
            }
            m[i][j] = ans;
        }
    }

    cout << m[1][n];
}