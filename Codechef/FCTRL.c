#include <stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,sum=0;
        scanf("%d",&n);
        while(n!=0)
        {
            n=n/5;
            sum+=n;
        }
        printf("%d\n",sum);
    }
    return 0;
}
