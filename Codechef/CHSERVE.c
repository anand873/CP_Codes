#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int p1,p2,k,k1;
        scanf("%d %d %d",&p1,&p2,&k);
        k1=2*k;
        if((p1+p2)%k1<k) printf("CHEF\n");
        else printf("COOK\n");
    }
    return 0;
}
