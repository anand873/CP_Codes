#include <stdio.h>
#include <math.h>

int f(int n)
{
    int t;
    t=sqrt(n);
    if(t*t==n) return 4*t;
    if((t*t+1)==n||t*(t+1)+1==n) return f(n-1)+2;
    return f(n-1);
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",f(n));
    return 0;
}
