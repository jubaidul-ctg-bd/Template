//******Big Number Factorial***//

//very big factorial
void BigFactorial(int n)
{
    int a[200];
    int i,j,temp,m,x;
    a[0]=1;
    m=1;
    temp = 0;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<m;j++)
        {
            x = a[j]*i+temp;
            a[j]=x%10;
            temp = x/10;
        }
        while(temp>0)
        {
            a[m]=temp%10;
            temp = temp/10;
            m++;
        }
    }
    for(i=m-1;i>=0;i--)
        cout << a[i];
    cout << endl;
}
