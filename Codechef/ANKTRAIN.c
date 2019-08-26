#include <stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int o,n,m;
        scanf("%d",&n);
        m=n%8;
        o=n/8;
        if(m==1||m==4) printf("%dLB\n",8*o+5-m);
        if(m==2||m==5) printf("%dMB\n",8*o+7-m);
        if(m==3||m==6) printf("%dUB\n",8*o+9-m);
        if(m==7) printf("%dSU\n",8*o+8);
        if(m==0) printf("%dSL\n",8*o-1);
    }
    return 0;
}
