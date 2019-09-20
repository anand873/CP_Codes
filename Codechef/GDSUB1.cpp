#include <bits/stdc++.h>
using namespace std;
#define N 1000000007

long long int power(int z,int y)
{
    long long int x=z;
    long long int res=1;
    x%=N;
    while(y>0)
    {
        if(y%2==1)
        {
            res =(res*x)%N;
            y--;
        }
        y/=2;
        x=(x*x)%N;
    }
    return res;
}

long long int MInv(int n)
{
    return power(n,N-2);
}

long long int nCr(int n,int r,long long int fact[])
{
    if(r<0) return 0;
    if(r==0) return 1;
    return (((fact[n]*(MInv(fact[r])%N))%N)*(MInv(fact[n-r])%N))%N;
}

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    long long int fact[8001];
    fact[0]=1;
    int i;
    for(i=1;i<8001;i++)
    {
        fact[i]=(fact[i-1]*i)%N;
    }
    int A[8001]={0};
    for(i=0;i<n;i++)
    {
        int j;
        scanf("%d",&j);
        A[j]++;
    }
    vector<int> S;
    for(i=0;i<8001;i++)
    {
        if(A[i]!=0) S.push_back(A[i]);
    }
    if(S.size()==n)
    {
        long long int sum=0;
        for(i=0;i<k+1;i++)
        {
            sum+=nCr(n,i,fact);
            sum%=N;

        }
        printf("%lld\n",sum);
    }
    else
    {
        if(S.size()<=k)
        {
            long long int sum=1;
            for(i=0;i<S.size();i++)
            {
                sum*=(S[i]+1);
                sum%=N;
            }
            printf("%lld\n",sum);
        }
        else
        {
            long long int sum=0;
            long long int B[S.size()+1]={0};
            B[0]=1;
            for(i=0;i<S.size();i++)
            {
                int j=i;
                while(j>=0)
                {
                    B[j+1]=(B[j]*S[i]+B[j+1])%N;
                    j--;
                }
            }
            for(i=0;i<=k;i++) {sum+=B[i]%N;sum%=N;}
            printf("%lld\n",sum);
        }
    }
}

