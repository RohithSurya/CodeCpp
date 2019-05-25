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
int c(int i, int j)
{
    if (i == -1 || j == -1)
        return 0;
    else if (m[i][j] != -1)
        return m[i][j];
    else if (s1[i] == s2[j])
        return m[i][j] = 1 + c(i - 1, j - 1);
    else
        return m[i][j] = max(c(i - 1, j), c(i, j - 1));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/mnt/c/Users/prsur/projects/helloworld/input.txt", "r", stdin);
    freopen("/mnt/c/Users/prsur/projects/helloworld/output.txt", "w", stdout);
#endif
    cin >> s1 >> s2;
    REP(i, 0, s1.length() + 1, 1)
    {
        REP(j, 0, s2.length() + 1, 1)
        {
            m[i][j] = -1;
        }
    }
    cout << c(s1.length()-1, s2.length()-1);
}