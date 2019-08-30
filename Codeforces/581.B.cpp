#include <stdio.h>
#include <bits/stdc++.h>
#include <math.h>

int minsum(int n,int l)
{
    int sum=0;
    int used=0;
    int x=pow(2,l-1);
    while(x>1)
    {
        used+=1;
        sum+=x;
        x/=2;
    }
    sum+=(n-used);
    return sum;
}

int maxsum(int n,int r)
{
    int sum=0;
    int used=0;
    int x=pow(2,r-1);
    int y=1;
    while(y<x)
    {
        used+=1;
        sum+=y;
        y*=2;
    }
    sum+=(n-used)*x;
    return sum;
}

int main()
{
    int n,l,r;
    scanf("%d%d%d",&n,&l,&r);
    printf("%d %d\n",minsum(n,l),maxsum(n,r));
}
