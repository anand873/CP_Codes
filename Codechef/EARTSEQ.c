#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void P(int n, int *primes)
{
    int i,j,count=0;
    primes[count++] = 2;
    if (count == n) return;
    for(i=3;i<=1000000;i+=2)
    {
        int isPrime=1;
        int jMax = sqrt(i);
        for(j=3;j<=jMax;j+=2)
        {
            if(i%j==0)
            {
                isPrime=0;
                break;
            }
        }
        if(isPrime)
        {
            primes[count++] = i;
            if(count==n) return;
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int maxPrime;
        maxPrime=(n+6)/2;
        int primes[maxPrime];
        P(maxPrime,primes);
        int i;
        if(n%4==3)
        {
            printf("6");
            for(i=1;i<n;i++)
            {
                if(i%4==0||i%4==1)
                {
                    printf(" %d",2*primes[i/2+i%4+1]);
                }
                else
                {
                    printf(" %d",3*primes[i/2+i%4-1]);
                }
            }
            printf("\n");
        }
        if(n%4==1)
        {
            printf("15");
            for(i=0;i<n-3;i++)
            {
                if(i%4==0||i%4==1)
                {
                    printf(" %d",2*primes[i/2+i%4+2]);
                }
                else
                {
                    printf(" %d",5*primes[i/2+i%4]);
                }
            }
            if(n==5)
            {
                printf(" %d",13*primes[(n+2)/2]);
                printf(" 39\n");
            }
            else
                {
                    printf(" %d",7*primes[(n+2)/2]);
                    printf(" 21\n");
                }
        }
        if(n%2==0)
        {
            printf("15");
            for(i=0;i<n-2;i++)
            {
                if(i%4==0||i%4==1)
                {
                    printf(" %d",2*primes[i/2+i%4+2]);
                }
                else
                {
                    printf(" %d",5*primes[i/2+i%4]);
                }
            }
            printf(" %d\n",primes[(n+2)/2]*3);
        }
    }
    return 0;
}
