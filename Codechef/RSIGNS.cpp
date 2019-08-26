#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
//#define N 10000007;

long long int Twon(long long int k)
{
    long long int temp;
    if(k==0) return 1;
    temp=Twon(k/2)%1000000007;
    //printf("%lld\n",temp);
    long long int tem;
    tem=temp*temp;
    tem%=1000000007;
    if(k%2==0) return tem;
    else return 2*tem;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int k;
        scanf("%lld",&k);
        long long int l;
        l=Twon(k-1)*10;
        l%=1000000007;
        printf("%lld\n",l);
    }
    return 0;
}
