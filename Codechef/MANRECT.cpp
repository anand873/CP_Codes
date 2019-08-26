#include <iostream>
#include <cstdlib>
#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int inp;
        long long int a=0,b=1000000000;
        printf("Q 0 0\n");
        fflush (stdout);
        long long int x;
        scanf("%lld",&x);
        printf("Q 0 %lld\n",b);
        fflush (stdout);
        long long int y;
        scanf("%lld",&y);
        y=b-y;
        printf("Q %lld 0\n",b);
        fflush (stdout);
        long long int z;
        scanf("%lld",&z);
        z=b-z;
        long long int w;
        long long int u;
        w=(x+z)/2;
        printf("Q %lld 0\n",w);
        fflush (stdout);
        scanf("%lld",&u);
        long long int xl,yl,xu,yu;
        yl=u;
        xl=x-yl;
        xu=z+yl;
        yu=y+xl;
        printf("A %lld %lld %lld %lld\n",xl,yl,xu,yu);
        fflush (stdout);
        scanf("%d",&inp);
        if(inp<0) goto en;
    }
    en:return 0;
}
