//****Code For Finding Combinations 1067-LightOj ****//
#include <bits/stdc++.h>
#define pb push_back
#define maxx 1000005
#define MOD 1000003

using namespace std;
typedef long long ll;
typedef unsigned long long ull;


ll BigMod(ll a,ll r,ll Mod)
{
    ll ret=1;

    while(r)    {
        if(r&1)    {
            ret=ret*a;
            ret=ret%Mod;
        }
        a=a*a;
        a=a%Mod;
        r=r/2;
    }

    return ret;
}

//InverseMOD
ll InverseMod(ll a,ll Mod)
{
    return BigMod(a,Mod-2,Mod);
}

ll fac[maxx];
ll inversfac[maxx];

void genfac()
{
    fac[0] = 1;
    inversfac[0] = 1;
    for(ll i=1; i<=maxx; i++)
    {
        fac[i] = i*fac[i-1];
        fac[i] = fac[i]%MOD;

        inversfac[i] = inversfac[i-1]*InverseMod(i, MOD);
        inversfac[i] = inversfac[i]%MOD;
    }
}

int main()
{
    genfac();
    ll t;
    cin >> t;
    for(ll i=1; i<=t; i++)
    {
        ll x, y;
        cin >> x >> y;

        ll ans= fac[x];
        ans = ans*inversfac[y];
        ans = ans*inversfac[x-y];
        ans = ans%MOD;
        printf("Case %lld: %lld\n", i, ans);
    }

    return 0;
}
