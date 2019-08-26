#include <stdio.h>
#define max 100000
int a[max];
int min(int a,int b)
{
    if(a<b) return a;
    return b;
}
int main()
{
    int i;
    for(i=0;i<max;i++) a[i]=((i+1)*(i+2))/2;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int x;
        scanf("%d",&x);
        for(i=0;i<max;i++)
        {
            if(x<a[i])
            {
                printf("%d\n",min((i+x-a[i-1]),i+1+a[i]-x));
                goto end;
            }
        }
        end: continue;
    }
    return 0;
}
