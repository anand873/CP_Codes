#include <stdio.h>

int gcd(int a,int b)
{
    while(a!=b)
    {
        if(a>b) a-=b;
        else b-=a;
    }
    return a;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,t,x,y,z;
        scanf("%d %d %d %d %d",&n,&t,&x,&y,&z);
        int nu,de;
        de=2*n+1;
        if(t==1)
        {
            if(x<y&&y>z)
            {
                printf("%d %d\n",x/gcd(x,de),de/(gcd(x,de)));
            }
            if(x<y&&z>y)
            {
                printf("%d %d\n",(de-z)/gcd(de-z,de),de/(gcd(de-z,de)));
            }
            if(x>y&&z>y)
            {
                printf("%d %d\n",x/gcd(x,de),de/(gcd(x,de)));
            }
            if(x>y&&y>z)
            {
                printf("%d %d\n",(de-z)/gcd(de-z,de),de/(gcd(de-z,de)));
            }
        }
        if(t==2||t==4)
        {
            printf("%d %d\n",(de-2*y)/gcd(de-2*y,de),de/(gcd(de-2*y,de)));
        }
        if(t==3)
        {
           if(x<y&&y<z)
            {
                printf("%d %d\n",(de-x)/gcd(de-x,de),de/(gcd(de-x,de)));
            }
            if(x<y&&z<y)
            {
                printf("%d %d\n",x/gcd(x,de),de/(gcd(x,de)));
            }
            if(x>y&&z>y)
            {
                printf("%d %d\n",x/gcd(x,de),de/(gcd(x,de)));
            }
            if(x>y&&y>z)
            {
                printf("%d %d\n",(de-x)/gcd(de-x,de),de/(gcd(de-x,de)));
            }
        }
    }
    return 0;
}
