//***Mobius Function Implementation***//

#define MAXN 100000000LL

bool siv[MAXN+7];
int mob[MAXN+7];
int pr[MAXN+7];
int tot;

//Sieve
void gen1()
{
    mob[1]=1;
    for(int i=2;i<=MAXN;i++)    {
        if(siv[i])    {
            siv[i]=1;
            if(mob[i]==2||mob[i]==-2)    mob[i]=0;
            continue;
        }
        mob[i]=-1;
        for(int j=i*2;j<=MAXN;j+=i)    {
            siv[j]=1;
            if(j%(i*i)==0)    mob[j]=2;
            else if(!mob[j])    mob[j]=-1;
            else    mob[j]*=-1;
        }
    }
}
