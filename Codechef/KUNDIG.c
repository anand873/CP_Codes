#include <stdio.h>
#include <math.h>

long long int f(int n)
{
    if(n==1) return 1;
    return n*f(n-1);
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int i,num[n];
        long long int sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&num[i]);
            sum += num[i];
        }
        sum = sum*(pow(10,n)-1)*f(n-1)/9;
        printf("%lld\n",sum);
    }
    return 0;
}
