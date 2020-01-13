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
			string s;
			cin>>s;
			int n=s.length();
			int i;
			int A[n],B[n];
			int k=0;
			vector<int> robs;
			for(i=0;i<n;i++)
			{
				if(s[i]!='.')
				{
					robs.push_back(i);
					A[i]=max(0,i-(s[i]-'0'));
					B[i]=min(i+(s[i]-'0'),n-1);
				}
				else {A[i]=n+1;B[i]=-1;}
			}

			for(i=0;i<n;i++)
			{
				if(s[i]!='.'&&k<robs.size()-1)
				{
					if(B[robs[k]]>=A[robs[k+1]])
					{
						cout<<"unsafe\n";
						goto en;
					}
					k++;
				}
			}
			cout<<"safe\n";
			en:;
		}
}