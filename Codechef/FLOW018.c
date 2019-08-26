#include <stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int n,m,i;
        scanf("%lld",&n);
        m=n;
        if(n==0) printf("1\n");
        else{
        for (i=1;i<m;i++)
        {
            n=n*i;
        }
        printf("%lld\n",n);
        }
    }
}
