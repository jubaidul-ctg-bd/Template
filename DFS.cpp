//*****DFS(Depth First Search)***///

// Recursive Algo
vector <int> adj[10];
bool visited[10];

void dfs(int s) {
    visited[s] = true;
    for(int i = 0;i < adj[s].size();++i)    {
     if(visited[adj[s][i]] == false)
         dfs(adj[s][i]);
    }
}


//*****DFS(Matrix)****//

ll n, m;
string s[1005];
bool vis[1005][1005];

ll x[4]={0,0,1,-1};
ll y[4]={1,-1,0,0};

void dfs(ll a,ll b)
{
    vis[a][b]=true;

    for(int i = 0;i < 4; ++i)    {
        if(x[i]+a>=0 && y[i]+b>=0 && x[i]+a<=n && y[i]+b<=n && s[a+x[i]][b+y[i]]=='0' && vis[a+x[i]][b+y[i]] == false)
            dfs(x[i]+a, y[i]+b);
    }
}
