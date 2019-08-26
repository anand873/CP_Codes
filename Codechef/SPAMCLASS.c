#include <stdio.h>
int main()
{
    int t,m,n,i,minx,maxx;
    scanf("%d",&t);
    for (m=0;m<t;m++)
    {
        int k=0,l=0;
        scanf("%d %d %d",&n,&minx,&maxx);
        int w[n],b[n];
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&w[i],&b[i]);
        }
        int minx0=minx;
        for(i=0;i<n;i++)
        {
            minx0 = minx0*w[i] + b[i];
        }
        int minx1 = minx + 1;
         for(i=0;i<n;i++)
        {
            minx1 = minx1*w[i] + b[i];
        }
        if ((minx0%2)==0 && (minx1%2)==0) {k=maxx-minx+1; l=0;}
        if ((minx0%2)==0 && (minx1%2)!=0) {if((maxx-minx+1)%2==0){k=(maxx-minx+1)/2; l=(maxx-minx+1)/2;}else k=(maxx-minx+2)/2;l=(maxx-minx)/2;}
        if ((minx0%2)!=0 && (minx1%2)==0) {if((maxx-minx+1)%2==0){k=(maxx-minx+1)/2; l=(maxx-minx+1)/2;}else k=(maxx-minx)/2;l=(maxx-minx+2)/2;}
        if ((minx0%2)!=0 && (minx1%2)!=0) {k=0; l=maxx-minx+1;}
        printf("%d %d\n",k,l);
    }
    return 0;
}
