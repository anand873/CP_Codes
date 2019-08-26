#include <stdio.h>

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    long long int A[n],B[m];
    int i;
    int Amax=0,Bmin=0;
    for(i=0;i<n;i++)
        {
            scanf("%lld",&A[i]);
            if(A[i]>A[Amax]) Amax=i;
        }
    for(i=0;i<m;i++)
    {
        scanf("%lld",&B[i]);
        if(B[i]<B[Bmin]) Bmin=i;
    }

    for(i=0;i<n;i++)
    {
        printf("%d %d\n",i,Bmin);
    }
    for(i=0;i<m;i++)
    {
        if(i==Bmin) goto ho;
        printf("%d %d\n",Amax,i);
        ho:;
    }
    return 0;
}
