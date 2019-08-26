#include <stdio.h>
#include <string.h>
long long int fact(int n)
{
    long long int fact=1;
    int i;
    for(i=n;i>0;i--)
    {
        fact=fact*i;
        fact=fact%1000000007;
    }
    return(fact);
}
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        char s[37];
        scanf("%s",&s);
        n=36-strlen(s);
        if(n!=0)
            {

                printf("%lld\n",fact(n));
            }
        else printf("1\n");
    }
}
