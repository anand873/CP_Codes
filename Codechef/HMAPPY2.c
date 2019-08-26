#include <stdio.h>

long long int gcd(long long int a,long long int b)
{
    while(a!=b)
    {
        if(a>b) a-=b;
        else b-=a;
    }
    //printf("%lld\n",a);
    return a;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int n,a,b,k;
        long long int g;
        scanf("%lld %lld %lld %lld",&n,&a,&b,&k);
        g=gcd(a,b);
        long long int l;
        l=a*b/g;
        //printf("%lld %lld %lld\n",a,b,l);
        long long int x;
        x=(n/a)+(n/b)-(2*(n/l));
        if(x>=k) printf("Win\n");
        else printf("Lose\n");
    }
    return 0;
}
