#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int N;
        int a,b;
        scanf("%d %d %d",&N,&a,&b);
        long long int A[N];
        int i,ma=0,mb=0,mab=0;
        for(i=0;i<N;i++)
        {
            scanf("%lld",&A[i]);
            if(A[i]%a==0) ma++;
            if(A[i]%b==0) mb++;
            if(A[i]%a==0&&A[i]%b==0) {ma--;mb--;mab++;}
        }
        if(ma>mb) printf("BOB\n");
        else
        {
            if(mab==0) printf("ALICE\n");
            else
            {
                if(ma==mb) printf("BOB\n");
                else printf("ALICE\n");
            }
        }
        /*if(mab%2==1) ma++;
        if(ma>mb) printf("BOB\n");
        else printf("ALICE\n");*/
    }
    return 0;
}
