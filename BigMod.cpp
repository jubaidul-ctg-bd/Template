//****BigMOD****//

// This function finds :  a^r % Mod in O(log2(r)) time complexity. This is a slower implementation of BigMod.
ll BigModRecursive(ll a,ll r,ll Mod)
{
    if(r==0)    return 1;

    ll ret=BigModRecursive(a,r/2,Mod);
    ret=ret*ret;
    ret=ret%Mod;

    if(r%2==1)    {
        ret=ret*a;
        ret=ret%Mod;
    }
    return ret;
}

// This function finds :  a^r % Mod in O(log2(r)) time complexity. This is the fastest implementation of BigMod.
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
