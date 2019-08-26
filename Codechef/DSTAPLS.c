#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int n,k;
        scanf("%lld%lld",&n,&k);
        long long int d=n/k;
        if(d%k==0) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
