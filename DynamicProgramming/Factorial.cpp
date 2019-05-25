/**
 * @author: Podugu Rohith Surya
 * @link: https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/tutorial/
 * @desc: Find Factorial of a given number mod 1000000007
 * Input: Given q test cases.
 * Output:factorial of a number % 1000000007
 **/
#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mset(A, a) memset(A, a, sizeof(A))
#define REP(i, a, b, k) for (__typeof(a) i = a; i < b; i += k)
typedef long long ll;
using namespace std;
const int N = 1e5 + 3;
const int MOD = 1000000007;
ll fact[N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    fact[0] = 1;
    fact[1] = 1;
    REP(i, 2, N, 1)
    {
        fact[i] = (i * fact[i - 1]) % MOD;
    }
    int q, temp;
    cin >> q;
    while (q--)
    {
        cin >> temp;
        cout << fact[temp] << endl;
    }
}