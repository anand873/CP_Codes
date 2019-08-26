#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define H 1000000007

long long int Fact[1000001];

int main()
{
    Fact[1]=1;
    int t,i;
    scanf("%d",&t);
    for(i=2;i<=1000001;i++)
    {
        Fact[i]=Fact[i-1]*i;
        if(Fact[i]>H) Fact[i]%=H;
    }
    while(t--)
    {
        int n;
        scanf("%d",&n);
        printf("%lld\n",Fact[n+1]-1);
    }
}
