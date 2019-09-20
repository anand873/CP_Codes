#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int n;
        long long int m;
        scanf("%lld%lld",&n,&m);
        if(n==1)
        {
            if(m==0) printf("0\n");
            if(m==1) printf("1\n");
            if(m>1) printf("-1\n");
        }
        if(n==2)
        {
            if(m==1) printf("1\n");
            if(m>1 && m<=3) printf("2\n");
            if(m==0 || m>3) printf("-1\n");
        }
        if(n!=1&&n!=2)
        {
            if(m>=n-1 && m<=n+1) printf("2\n");
            else if(m>n+1 && m<=2*n) printf("3\n");
            else if(m<n-1 || m>n*(n+1)/2) printf("-1\n");
            else
            {
                if(n%2==1)
                {
                    m-=2*n;
                    long long int k=m%n;
                    if(k==0) printf("%lld\n",3+(m/n)*2);
                    else if(k<=n/2) printf("%lld\n",3+(m/n)*2+1);
                    else printf("%lld\n",3+(m/n)*2+2);
                }
                else
                {
                    m-=2*n;
                    long long int k=m%n;
                    if(k==0) printf("%lld\n",3+(m/n)*2);
                    else if(k<=n/2) printf("%lld\n",3+(m/n)*2+1);
                    else printf("%lld\n",3+(m/n)*2+2);
                }
            }
        }
    }
}
