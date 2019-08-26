#include <stdio.h>

int main()
{
    long long int t;
    scanf("%lld",&t);
    while(t--)
    {
        long long int n,p;
        scanf("%lld %lld",&n,&p);
        int r;
        r=n%(n/2+1);
        if(n>2)
        {
            printf("%lld\n",(p-r)*(p-r)+(p-r)*(p-n)+(p-n)*(p-n));
        }
        if(n==2||n==1) printf("%lld\n",p*p*p);

    }
}
