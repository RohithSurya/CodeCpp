/**
 * @author: Podugu Rohith Surya;
 * @link: No link;
 * @desc: Matrix multiplication TopDown DP;
 * Input: No of matrices and after the dimensions of matrices;
 * Output: Single integer denoting the least multiplications;
 **/
#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mset(A, a) memset(A, a, sizeof(A))
#define REP(i, a, b, k) for (__typeof(a) i = a; i < b; i += k)
typedef long long ll;
using namespace std;
const int N = 1e3+5; //Change according to needs
int p[N];
int n;
int m[N][N];

int matrixMultiplication(int i, int j)
{
    if (m[i][j] != INT_MAX)
    {
        return m[i][j];
    }
    if (i == j)
    {
        return m[i][i] = 0;
    }
    else
    {
        int ans = INT_MAX;
        REP(k, i, j, 1)
        {
            ans = min(ans, matrixMultiplication(i, k) + matrixMultiplication(k + 1, j) + p[i - 1] * p[k] * p[j]);
        }
        return m[i][j] = ans;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("/mnt/c/Users/prsur/projects/helloworld/input.txt", "r", stdin);
    freopen("/mnt/c/Users/prsur/projects/helloworld/output.txt", "w", stdout);
#endif

    cin >> n;
    REP(i, 0, n + 1, 1)
    {

        cin >> p[i];
    }
    REP(i, 1, n + 1, 1)
    {
        REP(j, 1, n + 1, 1)
        {
            m[i][j] = INT_MAX;
        }
    }

    cout<<matrixMultiplication(1, n);
    
}