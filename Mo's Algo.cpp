#include <bits/stdc++.h>
#define MAXN 100000
#define SQMAX 350

using namespace std;
typedef long long ll;

struct qry {
    int L;
    int R;
    int id;
};

int n,m;
int ara[MAXN+5];
int blcSize, blcCnt;
vector<qry>blocks;
int ans[MAXN];
unordered_map<int,int>frq;
int okay=0;

bool cmp(qry q1,qry q2) {
    if(q1.L/blcSize==q2.L/blcSize) return q1.R<q2.R;
    return q1.L<q2.L;
}

void process(int x, bool add)
{
    int& val=frq[x];
    if(val==x) okay--;
    if(add)val++; else val--;
    if(val==x) okay++;
}

int main() {

    cin>>n>>m;
    blcSize=sqrt(n);
    blcCnt=n/blcSize;
    if(n%blcSize) blcCnt++;

    for(int i=0;i<n;i++) {
        cin>>ara[i];
    }

    for(int i=0;i<m;i++) {
        int l,r;
        cin>>l>>r; l--; r--;
        blocks.push_back({l,r,i});
    }

    sort(blocks.begin(),blocks.end(),cmp);

    int l=0;
    int r=-1;

    for(int blc=0;blc<m;blc++) {
        qry q=blocks[blc];

        while(l<q.L) {
            process(ara[l],0);
            l++;
        }
        while(l>q.L) {
            l--;
            process(ara[l],1);
        }
        while(r<q.R) {
            r++;
            process(ara[r],1);
        }
        while(r>q.R) {
            process(ara[r],0);
            r--;
        }
        ans[q.id]=okay;
    }

    for(int i=0;i<m;i++) {
        cout<<ans[i]<<"\n";
    }

    return 0;

}
