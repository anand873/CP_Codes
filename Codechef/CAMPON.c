#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int S[31]={0};
        int D;
        scanf("%d",&D);
        while(D--)
        {
            int d,p;
            scanf("%d %d",&d,&p);
            S[d-1]=p;
        }
        int Q;
        scanf("%d",&Q);
        while(Q--)
        {
            int dead,req;
            scanf("%d %d",&dead,&req);
            int i,sum=0;
            for(i=0;i<dead;i++)
            {
                sum=sum+S[i];
            }
            if(sum>=req) printf("Go Camp\n");
            else printf("Go Sleep\n");
        }
    }
    return 0;
}
