//****Fenwick Tree/Binary Indexed Tree/BIT****//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int ara[100005];
int bit[100005];

// BIT for sum

void update(int x,int val)
{
    for(int i=x;i<=n;i+=(i&-i))    bit[i]=bit[i]+val;
}
int query(int x)
{
    int ret=0;
    for(int i=x;i>0;i-=(i&-i))    ret+=bit[i];
    return ret;
}

int main()
{
    cin>>n;

    for(int i=1;i<=n;i++)    cin>>ara[i];

    int q;cin>>q;

    for(int i=0;i<q;i++)    {
        int cmd;
        cin>>cmd;
        if(cmd==1)    {
            int l,r;cin>>l>>r;
            cout<<query(r)-query(l-1)<<endl;
        }
        else    {
            int id,x;
            cin>>id>>x;
            update(id,x);
        }
    }


    return 0;
}
