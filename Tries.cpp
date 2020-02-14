#include <bits/stdc++.h>
using namespace std;

//********* Tries ************
int node[100005][26];
bool endmark[100005]; // mark to end point
int idCnt;

void build(string s,int len)
{
    int cur=0;
    for(int i=0; i<len; i++)
    {
        int val=s[i]-'0';
        if(node[cur][val]==0)
        {
            node[cur][val]=++idCnt;
        }
        cur=node[cur][val];
    }
    endmark[cur]=1;
}

bool search(string s, int len)
{
    int cur=0;
    for(int i=0; i<len; i++)
    {
        int val=s[i]-'0';
        if(node[cur][val]==0) return false;
        cur=node[cur][val];
    }
    return endmark[cur];
}



int main()
{
    //freopen("testcases.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int w; cin>>w;
    while(w--)
    {
        string s; cin>>s;
        build(s, s.size());
    }
    int q; cin>>q;
    while(q--)
    {
        string s; cin>>s;
        cout << search(s, s.size()) << endl;
    }
    return 0;
}
