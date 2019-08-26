#include <stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int total,n=0;
        scanf("%d",&total);
        n=n+total/2048;
        total=total%2048;
        n=n+total/1024;
        total=total%1024;
        n=n+total/512;
        total=total%512;
        n=n+total/256;
        total=total%256;
        n=n+total/128;
        total=total%128;
        n=n+total/64;
        total=total%64;
        n=n+total/32;
        total=total%32;
        n=n+total/16;
        total=total%16;
        n=n+total/8;
        total=total%8;
        n=n+total/4;
        total=total%4;
        n=n+total/2;
        total=total%2;
        n=n+total;

        printf("%d\n",n);
    }
    return 0;
}

