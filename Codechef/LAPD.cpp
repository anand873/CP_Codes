#include <bits/stdc++.h>
using namespace std;
#define N 1000000007

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b,c;
        //a=1000000000;
        //b=5000;
        //c=1000000000;
        scanf("%d%d%d",&a,&b,&c);
        long long int sum=0;
        int j,d,i,e;
        long long int k;
        for(j=1;j<=b;j++)
        {
            if(c>j+1&&a>j+1) sum+=((long long int)(c-j-1)*(a-j-1)%N)%N;
            d=min(a,j+1);
            for(i=2;i<=d;i++)
            {
                k=j*j/(i-1);
                if(c-k-1>0)
                {
                    sum+=(c-k-1)%N;
                }
            }
            e=min(c,j+1);
            for(i=2;i<=e;i++)
            {
                k=j*j/(i-1);
                if(a-k-1>0)
                {
                    sum+=(a-k-1)%N;
                }
            }
        }
        sum%=N;
        printf("%lld\n",sum);
    }
}
