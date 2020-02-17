//***Ternary Search***//
#include <bits/stdc++.h>
#define EPS 1e-9

using namespace std;
typedef long long ll;



int main()
{
    //freopen("testcases.txt","r",stdin);


    double a,b,c,d,L,R;

    cin>>a>>b>>c>>d>>L>>R;


    double l=L;
    double r=R;
    double m1,m2;
    double ans;


    while(r-l>EPS)    {
        m1=l+(r-l)/3.0;
        double fm1=a*m1*m1*m1+b*m1*m1+c*m1+d;

        m2=r-(r-l)/3.0;
        double fm2=a*m2*m2*m2+b*m2*m2+c*m2+d;

        if(fabs(fm1-fm2)<EPS)    {
            ans=fm1;
            break;
        }
        else if(fm1<fm2)    {
            l=m1;
        }
        else    {
            r=m2;
        }
    }


    cout<<ans<<endl;

    /*

    //Iterative Approach

    for(int i=0;i<100;i++)    {
        m1=l+(r-l)/3.0;
        double fm1=a*m1*m1*m1+b*m1*m1+c*m1+d;

        m2=r-(r-l)/3.0;
        double fm2=a*m2*m2*m2+b*m2*m2+c*m2+d;

        if(fabs(fm1-fm2)<EPS)    {
            ans=fm1;
            break;
        }
        else if(fm1<fm2)    {
            l=m1;
        }
        else    {
            r=m2;
        }
    }

    cout<<ans<<endl;


    */



    return 0;
}
