//****Segment Tree***//

// Implementation for Range Query Point Update ( Without Lazy )
#define MAXN 100000
int ara[MAXN+7];
int tree[4*MAXN+7];

// for example subrange sum in used.

void buildTree(int node,int l,int r)
{
    if (l==r)    {tree[node]=ara[l];return;}
    int mid=(l+r)/2;
    buildTree(2*node,l,mid);
    buildTree(2*node+1,mid+1,r);
    tree[node]=tree[2*node]+tree[2*node+1];
}

int query(int node,int l,int r,int L,int R)
{
    if (L>r || R<l)    return 0;
    if (l>=L && r<=R)    return tree[node];
    int mid=(l+r)/2;
    int ql=query(2*node,l,mid,L,R);
    int qr=query(2*node+1,mid+1,r,L,R);
    return ql+qr;
}

void update(int node,int l,int r,int idx,int val)
{
    if (idx>r || idx<l) return;
    if (l==r)    {tree[node]=val;return;}
    int mid=(l+r)/2;
    update(2*node,l,mid,idx,val);
    update(2*node+1,mid+1,r,idx,val);
    tree[node]=tree[2*node]+tree[2*node+1];
}
