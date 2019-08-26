#include <stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int d,n,sum=0;
        scanf("%d %d",&d,&n);
        while (d--)
        {
           n = n*(n+1)/2;
        }
        printf("%d\n",n);
    }
    return 0;
}
