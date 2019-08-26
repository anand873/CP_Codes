#include <iostream>
#include <stdio.h>
#include <cstdlib>

int main()
{
    int m;
    m=1000;
    int n,c;
    scanf("%d %d",&n,&c);
    if(n<=1000)
    {
        int x;
        printf("1 1\n");
        fflush(stdout);
        m--;
        int s1,sn=1;
        scanf("%d",&s1);
        if(s1==1)
        {
            printf("2\n");
            fflush(stdout);
            m-=c;
            printf("3 1\n");
            fflush(stdout);
            return 0;
        }
        x=n/160;
        int p=1;
        while(m>0)
        {
            printf("1 %d\n",x);
            fflush(stdout);
            m--;
            int inp;
            scanf("%d",&inp);
            if(inp==1)
            {
                printf("2\n");
                fflush(stdout);
                m-=c;
            }
            if(s1==inp) {p=x;x=(7*x+n)/8+1;goto yo;}
            if(sn==inp)
            {
                n=x;
                if(x-p<320) x=(p+x)/2;
                else x=(319*p+x)/320;
            }
            yo:;
            if(n-p==1) {printf("3 %d\n",n); fflush(stdout);return 0;}
        }
    }
    else
    {
        int nf;
        nf=n;
        printf("1 1\n");
        fflush(stdout);
        m--;
        int s1,sn=1;
        scanf("%d",&s1);
        if(s1==1)
        {
            printf("2\n");
            fflush(stdout);
            m-=c;
            printf("3 1\n");
            fflush(stdout);
            return 0;
        }
        int inp;
        int i,x=1,p=1,q=1;
        while(m)
        {
            while(1)
            {
            t:  x=x+(n-p+1)/10;
                if(x>nf) printf("1 %d\n",n);
                else printf("1 %d\n",x);
                fflush(stdout);
                m--;
                scanf("%d",&inp);
                if(inp==0) {q=x;goto t;}
                else
                {
                    printf("2\n");
                    if(x-q==1)
                    {
                        printf("3 %d\n",x);
                        fflush(stdout);
                        goto en;
                    }
                    m-=c;
                    p=q;
                    n=x-1;
                    x=p;
                    goto go;
                }
            }
        go:;
        }
    en: return 0;
    }
}

