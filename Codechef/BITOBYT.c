#include <stdio.h>
#include <math.h>

int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n;
        scanf("%d",&n);
        int a;
        long long int x;
        a=n/26;
        x=pow(2,a);
        if(n%26<=2&&n%26>0) printf("%lld 0 0\n",x);
        if(n%26>2&&n%26<=10) printf("0 %lld 0\n",x);
        if(n%26>10&&n%26<26) printf("0 0 %lld\n",x);
        if(n%26==0) printf("0 0 %lld\n",x/2);
    }
    return 0;
}

