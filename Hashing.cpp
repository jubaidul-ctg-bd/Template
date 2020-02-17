//***Hashing Implementation***//


ll base[maxx];
ll inversbase[maxx];
ll mod=293114467;


void basegenerate(ll bz)
{
    base[0]=1;
    inversbase[0]=1;
    ll inv = InverseMod(bz,mod);
    for(ll i=1; i<maxx; i++)
    {
        base[i]=(base[i-1]*bz)%mod;
        inversbase[i]=(inversbase[i-1]*inv)%mod;
    }
    for(ll i=1; i<maxx; i++) inversbase[i]=(inversbase[i-1]+inversbase[i])%mod;
}




ll hashing(string s, ll (&encode)[maxx] )
{
    ll l=s.size();
    encode[0]=(s[0]*base[0])%mod;
    for(ll i=1; i<l; i++)
    {
        encode[i]=(encode[i-1]+((s[i]*base[i])%mod))%mod;
    }
}


ll hashValue(ll l, ll r, ll (&encode)[maxx])
{
    return (encode[r]-encode[l-1])*inversbase[l-1];
}


int main()
{
    //freopen("testcases.txt","r",stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    basegenerate(1000);
    string s;
    while(cin>>s)
    {
        ll arr[maxx];
        hashing(s, arr);
        ll x,y; cin>>x>>y;
        cout << hashValue(x, y, arr) << endl;
    }

    return 0;
}
