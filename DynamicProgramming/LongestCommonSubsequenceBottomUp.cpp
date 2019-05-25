/**
 * @author: Podugu Rohith Surya;
 * @link: No Link;
 * @desc: Longest common subsequence;
 * Input: Two strings s1 s2;
 * Output: Length of longest common subsequence;
 **/

#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mset(A, a) memset(A, a, sizeof(A))
#define REP(i, a, b, k) for (__typeof(a) i = a; i < b; i += k)
typedef long long ll;
using namespace std;
const int N = 1e4 + 5; //Change according to needs
int m[N][N];
string s1, s2;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("/mnt/c/Users/prsur/projects/helloworld/input.txt", "r", stdin);
    freopen("/mnt/c/Users/prsur/projects/helloworld/output.txt", "w", stdout);
#endif
    cin >> s1 >> s2;
    REP(i, 0, s2.length() + 1, 1)
    {
        m[0][i] = 0;
    }
    REP(i, 0, s1.length() + 1, 1)
    {
        m[i][0] = 0;
    }
    REP(i, 1, s1.length() + 1, 1)
    {
        REP(j, 1, s2.length() + 1, 1)
        {
            if (s1[i - 1] == s2[j - 1])
                m[i][j] = 1 + m[i - 1][j - 1];
            else
                m[i][j] = max(m[i - 1][j], m[i][j - 1]);
        }
    }
    cout << m[s1.length()][s2.length()];
}