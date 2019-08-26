#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int A[n],D[n];
        int i;
        int max=0,c=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&A[i]);
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&D[i]);
            if(D[i]>A[(n+i-1)%n]+A[(n+i+1)%n])
            {
                if(c==i) max=i;
                else if(D[max]<D[i]) max=i;
            }
            else c++;
        }
        if(c==n) printf("-1\n");
        else printf("%d\n",D[max]);
    }
    return 0;
}
