//Author: AnandRaj uux
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pll> vpll; 

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define test() int t;cin>>t;while(t--)
#define forn(i,f,n) for(int i=f;i<f+n;i++)
#define rforn(i,l,n) for(int i=l;i>l-n;i--)
#define all(v) v.begin(),v.end()
#define prin(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int i=f;i<f+n;i++) cin>>V[i]
#define what(x) cerr<<#x<<" = "<<x<<endl
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "

const int MOD = 1e9+7,MAX = 2e5+5;
/////////////////FastExp///////////////////
ll powN(ll a,ll p)
{
	if(p==0) return 1;
	ll z=powN(a,p/2);
	z=(z*z)%MOD;
	if(p%2) z=(z*a)%MOD;
	return z;
}
/////////////////FastExp///////////////////
//////////////////Sieve////////////////////
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
            {
				is_prime[j] = false;
    		}
    	}
	}
}
//////////////////Sieve////////////////////

int main()
{
	int n,t;
	cin>>n>>t;
	vi A(n);
	vi P,N;
	take(A,0,n);
	int zero=0;
	for(int i=0;i<n;i++)
	{
		if(A[i]<0) N.push_back(-1*A[i]);
		else if(A[i]==0) zero=1;
		else P.push_back(A[i]);
	}
	sort(all(N));
	sort(all(P));
	int ans=0;
	for(int i=0;i<P.size();i++)
	{
		int currans=0;
		int remtime=t-P[i];
		if(remtime>=0)
		{
			currans=i+1;
			remtime-=P[i];
			if(remtime>0)
			{
				int low=0;
				int high=N.size()-1;
				int extra=0;
				while(low<=high)
				{
					int mid=low+(high-low)/2;
					if(N[mid]>remtime)
					{
						high=mid-1;
					}
					else
					{
						low=mid+1;
						extra=mid+1;
					}

				}
				currans+=extra;
			}
			ans=max(ans,currans);
		}
		else break;
	}

	for(int i=0;i<N.size();i++)
	{
		int currans=0;
		int remtime=t-N[i];
		if(remtime>=0)
		{
			currans=i+1;
			remtime-=N[i];
			what(remtime);
			if(remtime>0)
			{
				int low=0;
				int high=P.size()-1;
				int extra=0;
				while(low<=high)
				{
					int mid=low+(high-low)/2;
					if(P[mid]>remtime)
					{
						high=mid-1;
					}
					else
					{
						low=mid+1;
						extra=mid+1;
					}

				}
				currans+=extra;
			}
			ans=max(ans,currans);
		}
	}

	cout<<ans+zero<<endl;
}		