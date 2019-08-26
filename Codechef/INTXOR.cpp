#include <iostream>
#include <stdio.h>
#include <cstdlib>

void M4(int n,int k,long long int f[])
{
    int i;
    for(i=0;i<n/4;i++)
    {
        long long int x[4];
        printf("1 %d %d %d\n",4*i+1+k,4*i+2+k,4*i+3+k);
        fflush(stdout);
        scanf("%lld",&x[0]);
        printf("1 %d %d %d\n",4*i+1+k,4*i+2+k,4*i+4+k);
        fflush(stdout);
        scanf("%lld",&x[1]);
        printf("1 %d %d %d\n",4*i+1+k,4*i+3+k,4*i+4+k);
        fflush(stdout);
        scanf("%lld",&x[2]);
        printf("1 %d %d %d\n",4*i+2+k,4*i+3+k,4*i+4+k);
        fflush(stdout);
        scanf("%lld",&x[3]);
        f[4*i+k]=x[0]^x[1]^x[2];
        f[4*i+1+k]=x[0]^x[1]^x[3];
        f[4*i+2+k]=x[0]^x[2]^x[3];
        f[4*i+3+k]=x[1]^x[2]^x[3];
    }
}

void M5(int l,long long int f[])
{
    int i;
    for(i=0;i<l;i++)
    {
        long long int x[5];
        printf("1 %d %d %d\n",5*i+1,5*i+2,5*i+3);
        fflush(stdout);
        scanf("%lld",&x[0]);
        printf("1 %d %d %d\n",5*i+2,5*i+3,5*i+4);
        fflush(stdout);
        scanf("%lld",&x[1]);
        printf("1 %d %d %d\n",5*i+3,5*i+4,5*i+5);
        fflush(stdout);
        scanf("%lld",&x[2]);
        printf("1 %d %d %d\n",5*i+1,5*i+4,5*i+5);
        fflush(stdout);
        scanf("%lld",&x[3]);
        printf("1 %d %d %d\n",5*i+1,5*i+2,5*i+5);
        fflush(stdout);
        scanf("%lld",&x[4]);
        f[5*(i+1)-5]=x[1]^x[2]^x[4];
        f[5*(i+1)-4]=x[2]^x[3]^x[0];
        f[5*(i+1)-3]=x[3]^x[4]^x[1];
        f[5*(i+1)-2]=x[4]^x[0]^x[2];
        f[5*(i+1)-1]=x[0]^x[1]^x[3];
    }
}

void M7(int l,long long int f[])
{
    int i;
    for(i=0;i<l;i++)
    {
        long long int x[7];
        printf("1 %d %d %d\n",7*i+1,7*i+2,7*i+3);
        fflush(stdout);
        scanf("%lld",&x[0]);
        printf("1 %d %d %d\n",7*i+2,7*i+3,7*i+4);
        fflush(stdout);
        scanf("%lld",&x[1]);
        printf("1 %d %d %d\n",7*i+3,7*i+4,7*i+5);
        fflush(stdout);
        scanf("%lld",&x[2]);
        printf("1 %d %d %d\n",7*i+4,7*i+5,7*i+6);
        fflush(stdout);
        scanf("%lld",&x[3]);
        printf("1 %d %d %d\n",7*i+5,7*i+6,7*i+7);
        fflush(stdout);
        scanf("%lld",&x[4]);
        printf("1 %d %d %d\n",7*i+1,7*i+6,7*i+7);
        fflush(stdout);
        scanf("%lld",&x[5]);
        printf("1 %d %d %d\n",7*i+1,7*i+2,7*i+7);
        fflush(stdout);
        scanf("%lld",&x[6]);
        f[0]=x[0]^x[2]^x[3]^x[5]^x[6];
        f[1]=x[0]^x[1]^x[3]^x[4]^x[6];
        f[2]=x[0]^x[1]^x[2]^x[4]^x[5];
        f[3]=x[1]^x[2]^x[3]^x[5]^x[6];
        f[4]=x[0]^x[2]^x[3]^x[4]^x[6];
        f[5]=x[0]^x[1]^x[3]^x[4]^x[5];
        f[6]=x[1]^x[2]^x[4]^x[5]^x[6];
    }
}

int main()
{
    int t,i;
    scanf("%d",&t);
    while(t)
    {
        int n;
        scanf("%d",&n);
        long long int f[n];
        if(n%4==0) {M4(n,0,f);}
        if(n%4==1) {M5(1,f);M4(n-5,5,f);}
        if(n%4==2) {M5(2,f);M4(n-10,10,f);}
        if(n%4==3) {M7(1,f);M4(n-7,7,f);}
        printf("2");
        fflush(stdout);
        for(i=0;i<n;i++) printf(" %lld",f[i]);
        fflush(stdout);
        printf("\n");
        fflush(stdout);
        int ans;
        scanf("%d",&ans);
        if(ans==1) goto go;
        if(ans==-1) goto en;
        go:t--;
    }
en: return 0;
}
