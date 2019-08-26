#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,a,b,pa=0,pb=0;
        scanf("%d %d %d",&n,&a,&b);
        int arr[n];
        int i;
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
            if(arr[i]==a) pa++;
            if(arr[i]==b) pb++;
        }
        double p;
        p=(pa*pb*1.0)/(n*n*1.0);
        printf("%.10lf\n",p);
    }
    return 0;
}
