//***DSU***//

int par[100005]; // initially set par[i]=i for all i<=N.

int fnd(int node)
{
    if(par[node]==node)    return node;
    return par[node]=fnd(par[node]);
}

void uni(int x,int y)
{
    int xr=fnd(x);
    int yr=fnd(y);

    if(xr!=yr)    {
        par[xr]=yr;
    }
}

