#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define test(t) int t;cin>>t;while(t--)
#define forn(i,n) for(i=0;i<n;i++)
#define rforn(i,n) for(i=n-1;i>=0;i--)
const int MOD = 1e9+7,MAX = 1e5+5;
ll powN(ll a,ll p)
{
	if(p==0) return 1;
	ll z=powN(a,p/2);
	z=(z*z)%MOD;
	if(p%2) z=(z*a)%MOD;
	return z;
}
vector<bool> is_prime(MAX+1, true);
void Sieve()
{
	is_prime[0] = is_prime[1] = false;
	int i,j;
	for (i = 2; i*i <= MAX; i++) 
	{
    	if (is_prime[i]) 
    	{
        	for (j = i * i; j <= MAX; j += i)
            	is_prime[j] = false;
    	}
	}
}


int main()
{
		test(t)
		{
			int n,k;
			cin>>n>>k;
			int A[n],i;
			for(i=0;i<n;i++)
			{
				cin>>A[i];
			}
			sort(A,A+n);
			if(n==1)
			{
				cout<<A[0]<<endl;
				continue;
			}
			int sum=0;
			for(i=0;i<n;i++)
			{
				if(A[i]<=k) 
				{
					sum+=A[i];
					A[i]=0;
				}
				else
				{
					sum+=k;
					A[i]-=k;
				}
			}
			int su=0;
			for(i=0;i<n-2;i++)
			{
				su+=A[i];
			}
			if(su<A[n-2])
			{
				sum+=(A[n-1]-A[n-2]+su);
			}
			else
			{
				if((su-A[n-2])%2)
				{
					sum+=(A[n-1]-1);
				}
				else sum+=A[n-1];
			}
			cout<<sum<<endl;
		}
}