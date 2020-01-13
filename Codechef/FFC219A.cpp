#include <bits/stdc++.h>
using namespace std;
#define N 1000000007

int _pow(long long int i,int k)
{
	if(k%2==0) return ((long long int)(_pow(i,k/2)%N)*(_pow(i,k/2)%N))%N;
	else return ((long long int)i*(_pow(i,k-1)%N)%N);
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int m;
		int k;
		cin>>m>>k;
		int n;
		n=mN;
		long long int i;
		long long int sum=0;
		for(i=1;i<=m;i++)
		{
			sum=(sum+_pow(i%N,k))%N;
		}
		sum+=(k/2)*(k/2+1)%N;
		cout<<sum<<endl;
	}
}