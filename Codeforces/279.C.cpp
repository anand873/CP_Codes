//Author: AnandRaj doubleux
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
#define all(v) v.begin(),v.end()
#define prin(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int in=f;in<f+n;in++) cin>>V[in]
#define what(x) cerr<<#x<<" = "<<x<<endl
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "

const int MOD = 1e9+7,MAX = 1e6+5;
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
vector<bool> is_prime(MAX, true);
vector<int> MinDiv(MAX);
void Sieve()
{
	is_prime[0] = is_prime[1] = false;
	int i,j;
	for (i = 2; i*i <= MAX; i++) 
	{
    	if (is_prime[i]) 
    	{
    		MinDiv[i]=i;
        	for (j = i * i; j <= MAX; j += i)
            {
				is_prime[j] = false;
				MinDiv[j]=i;
    		}
    	}
	}
	for(int i=2;i<=MAX;i++) if(is_prime[i]) MinDiv[i]=i;
}
//////////////////Sieve////////////////////

int main()
{
	fastio
	int n,m;
	cin>>n>>m;
	vi A(n+1);
	take(A,1,n);

	for(int i=0;i<m;i++)
	{
		int l,r;
		cin>>l>>r;
		if(r-l<=1) {cout<<"Yes"<<endl;continue;}
		int hu=r,ld=l;
		int low=l,high=r-1;
		while(low<=high)
		{
			int mid=low+(high-low)/2;

			if(A[mid]<=A[mid+1])
			{
				hu=mid;
				low=mid+1;
			}
			else high=mid-1;
		}
		low=l+1;
		high=r;

		while(low<=high)
		{
			int mid=low+(high-low)/2;

			if(A[mid]<=A[mid-1])
			{
				ld=mid;
				high=mid-1;
			}
			else low=mid+1;
		}
		what(hu);
		what(ld);
		if(hu<=ld)
		{
			cout<<"Yes"<<endl;
		}
		else cout<<"No"<<endl;


	}
}		