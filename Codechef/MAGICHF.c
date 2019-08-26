#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,x,s;
        scanf("%d %d %d",&n,&x,&s);
        int i,b[n],c;
        for(i=0;i<n;i++) b[i]=0;
        b[x-1]=1;
        for(i=0;i<s;i++)
        {
            int b1,b2;
            scanf("%d %d",&b1,&b2);
            c=b[b1-1];
            b[b1-1]=b[b2-1];
            b[b2-1]=c;
        }
        for(i=0;i<n;i++)
        {
            if(b[i]==1) {printf("%d\n",i+1);break;}
        }
    }
    return 0;
}
