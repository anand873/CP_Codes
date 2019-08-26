#include <stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,i,j,count;
        scanf("%d",&n);
        int x[n],y[n];
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&x[i],&y[i]);
        }
        count = n/10;
        for(j=2;j<n-1;j++)
            {
                if(((x[0]+x[j])%2==0)&&((y[0]+y[j])%2==0))
                    {printf("%d %d\n",(x[0]+x[j])/2,(y[0]+y[j])/2);
                count--;}
                if(count==0) goto end;
            }
        for(i=1;i<n;i++)
        {
            for(j=i+2;j<n;j++)
            {
                if(((x[i]+x[j])%2==0)&&((y[i]+y[j])%2==0))
                    {printf("%d %d\n",(x[i]+x[j])/2,(y[i]+y[j])/2);
                count--;}
                if(count==0) goto end;
            }
        }
        if(count==n/10) printf("-1\n");
        end:;
    }
    return 0;
}
