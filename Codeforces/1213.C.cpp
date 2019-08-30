#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        long long int n,m;
        scanf("%lld%lld",&n,&m);
        int ld=m%10;
        long long int sum=0;
        if(ld==0)
        {
            sum=0;
        }
        else if(ld==5)
        {
            long long int a=n/m;
            if(a%2==0) sum=(a/2)*5;
            else sum=(a/2)*5+5;
        }
        else if(ld%2==0)
        {
            long long int a=n/m;
            sum=(a/5)*20;
            int b=a%5;
            while(b)
            {
                sum+=(ld*b)%10;
                b--;
            }
        }
        else
        {
            long long int a=n/m;
            sum=(a/10)*45;
            int b=a%10;
            while(b)
            {
                sum+=(ld*b)%10;
                b--;
            }
        }
        printf("%lld\n",sum);
    }
}

