//***Matrix Exponentiation***//

#include <bits/stdc++.h>
//#define MOD 1000000007

using namespace std;
typedef long long ll;

ll MOD = 1;

//Square Matix Only
struct Matrix{
    int len; //dimension of square matrix
    vector<vector<ll> >mat;
    Matrix(int l)
    {
        len=l;
        for(int i=0;i<len;i++)    {
            vector<ll>tmp;
            for(int j=0;j<len;j++)    tmp.push_back(0);
            mat.push_back(tmp);
        }
    }
    void setToUnitMatrix()
    {
        for(int i=0;i<len;i++)    {
            mat[i][i]=1;
        }
    }
};



//A and B are both square matrics and both have equal dimension
//It multilies A and B and stores into A
void MatMult(Matrix& A, Matrix& B)
{
    int dim=A.len;
    Matrix tmp(dim);


    for(int i=0;i<dim;i++)    {
        for(int j=0;j<dim;j++)    {
            for(int k=0;k<dim;k++)    {
                tmp.mat[i][j]+=A.mat[i][k]*B.mat[k][j];
                tmp.mat[i][j]%=MOD;
            }
        }
    }

    for(int i=0;i<dim;i++)    {
        for(int j=0;j<dim;j++)    {
            A.mat[i][j]=tmp.mat[i][j];
        }
    }
}

//Calculates A^r and returns.
Matrix MatExp(Matrix& A,ll r)
{
    int dim=A.len;
    Matrix ret(dim);
    ret.setToUnitMatrix();

    while(r)    {
        if(r&1)    {
            MatMult(ret,A);
        }
        MatMult(A,A);
        r=r/2;
    }

    return ret;
}


int main()
{
    //freopen("testcases.txt","r",stdin);

    ll  a, b , n ,m, t, tc=0; cin>>t;
    while(t--)
    {
        cin>>a>>b>>n>>m;
        MOD=1;
        for(ll i=1; i<=m; i++) MOD*=10;

        Matrix Fib(2);
        Fib.mat[0][0]=1;
        Fib.mat[0][1]=1;
        Fib.mat[1][0]=1;
        Fib.mat[1][1]=0;

        Matrix Fin= MatExp(Fib,n-1);
        a%=MOD;
        b%=MOD;
        if(n==0) cout << "Case "<<++tc<<": "<<a<<endl;
        else if(n==1) cout << "Case "<<++tc<<": "<<b<<endl;
        else {
            ll ans = ((Fin.mat[0][0]*b)%MOD)+((Fin.mat[0][1]*a)%MOD);
            cout << "Case "<<++tc<<": "<<ans%MOD<<endl;
        }
    }

    return 0;
}

