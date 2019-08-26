#include <stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,k,i,j;
        scanf("%d %d %d",&n,&m,&k);
        int a[m],b[k];
        for(i=0;i<m;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<k;i++)
        {
            scanf("%d",&b[i]);
        }
        int it=0,uu=0;
        for(i=0;i<m;i++)
        {
            for(j=0;j<k;j++)
            {
                if (a[i]==b[j]) it++;
            }
        }
        uu = it+n-m-k;
        printf("%d %d\n",it,uu);
    }
}
