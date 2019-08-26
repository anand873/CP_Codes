#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int i,A[n];
        long long int sum=0,j;
        for(i=0;i<n;i++)
        {
            scanf("%d",&A[i]);
            sum+=A[i];
        }
        j=sum-n+1;
        printf("%lld\n",j);
    }
    return 0;
}
