#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int l[n],g[n],i;
        for(i=0;i<n;i++)
        {
            scanf("%d",&l[i]);
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&g[i]);
        }
        int count=0;
        for(i=0;i<n;i++)
        {
            if(l[i]>g[i]) goto back;
        }
        count++;
        back:for(i=0;i<n;i++)
        {
            if(l[i]>g[n-i-1]) goto none;
        }
        count+=2;
        none:switch (count)
        {
            case 0: printf("none\n"); break;
            case 1: printf("front\n"); break;
            case 2: printf("back\n"); break;
            case 3: printf("both\n"); break;
        }
    }
    return 0;
}
