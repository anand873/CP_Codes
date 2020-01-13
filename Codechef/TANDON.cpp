#include <bits/stdc++.h>
using namespace std;
#define N 1000000007

long long int _pow(int x,int y)
{
	if(y==0) return 1;
	int p=_pow(x,y/2);
	if(y%2==0) return ((long long int)p*p)%N;
	else return ((((long long int)p*p)%N)*x)%N;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		long long int ans;
		if(k==10)
		{
			ans=1;
		}
		else if(k==2||k==4||k==5||k==7||k==8)
		{
			int p=9/k+1;
			ans=_pow(p,n);
		}
		else if(k==3)
		{
			ans=((_pow(10,n)-1)*333333336)%N+1;
		}
		else if(k==9)
		{
			ans=((_pow(10,n)-1)*111111112)%N+1;
		}
		else if(k==6)
		{
			;
		}
		cout<<ans<<endl;
	}
}