/**
 * @author: Podugu Rohith Surya
 * @link: https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/tutorial/
 * @desc: Given n bottles with profit values p[], for p[i] for each bottle, Only one bottle can be sold per year. The quality of wine increases every year, so the price. So price at year y is y*p[i], where i is the bottle sold.
 * The goal is to maximize the profit.
 * Input: One first line no of wine bottles, On the second line profit p[i] for each bottle.
 * Output: Maximum profit.
 **/

#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mset(A, a) memset(A, a, sizeof(A))
#define REP(i, a, b, k) for (__typeof(a) i = a; i < b; i += k)
typedef long long ll;
using namespace std;
const int N = 1e3 + 5;
int p[N];
int cache[N][N];
int n;


int profit(int beg, int end)
{
    if (beg > end)
    {
        return 0;
    }
    int year = n - (end - beg);
    if (cache[beg][end] != -1)
    {
        return cache[beg][end];
    }
    return cache[beg][end] = max(profit(beg + 1, end) + year * p[beg], profit(beg, end - 1) + year * p[end]);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n;

    REP(j, 0, n, 1)
    {
        cin >> p[j];
    }
    REP(i, 0, n + 1, 1)
    {
        REP(j, 0, n + 1, 1)
        {
            cache[i][j] = -1;
        }
    }
    cout << profit(0, n - 1) << endl;
}