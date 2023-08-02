#include <stdio.h>
#include <math.h>
int ned(int n)
{   n=n-1;
    n=n*(n+1)/2;
    return n;
}
int main ()
{
    long long n,number[3000],diff[3000],i,j,k,sum,tot;
     while ( scanf ("%lld",&n)!=EOF)
     {
    sum=0;
    tot=ned(n);
    for (i=0;i<n;i++)
    {
        scanf ("%lld",&number[i]);
    }
    for (i=0;i<n-1;i++)
    {
        diff[i]=abs(number[i+1]-number[i]);
    }
    for (i=0;i<n-2;i++)
    {
        for (j=i+1;j<n-1;j++)
        {
            if (diff[i]==diff[j])
            {
                diff[j]= (diff[i]+diff[j])/2;
                diff[i]=0;
                break;
            }
        }
    }
    for (k=0;k<n-1;k++)
    {
        sum=sum+diff[k];
    }
    if (sum==tot) printf ("Jolly\n");
    if (sum!=tot) printf ("Not jolly\n");
     }
    return 0;
}
