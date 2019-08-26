#include <stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int n;
        int i=0;
        scanf("%lld",&n);
        while(n)
        {
            if(n%10==4) i++;
                n=n/10;
        }
        printf("%d\n",i);
    }
    return 0;
}
