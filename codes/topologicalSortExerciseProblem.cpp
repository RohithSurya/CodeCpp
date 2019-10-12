#include<bits/stdc++.h>
#define f first
#define s second
#define pb push_back
typedef long long ll;
using namespace std;
const int N = 1e5+5;
vector<int> adj[N];
int inorder[N];
int visited[N];
int n,m;
int u,v;
set<int> s;
ll w;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    cin>>n>>m;
    for (int i = 1; i <= m; i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            inorder[adj[i][j]]++;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if(inorder[i]==0) q.push(i);
    }



    while (!q.empty())
    {
        int elem = q.front();
        q.pop();
        if(visited[elem]) continue;
        visited[elem] = 1;
        cout<<elem<<" ";
        for (int i = 0; i < adj[elem].size(); i++)
        {
            if(!visited[adj[elem][i]]) {
                inorder[adj[elem][i]]--;
                if(inorder[adj[elem][i]]==0) {
                   s.insert(adj[elem][i]);
                }
            }   
        }
        for(auto k: s) q.push(k);
        s.clear();
        
    }
    
}
