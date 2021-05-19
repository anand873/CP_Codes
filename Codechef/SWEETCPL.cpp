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
#define prinp(p) cout<<p.first<<" "<<p.second<<endl
#define prinv(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int in=f;in<f+n;in++) cin>>V[in]
#define what(x) cerr<<#x<<" = "<<x<<endl
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1e9 + 7,MAX = 1e6 + 5;
const ll INF = 1e18+5;

struct Sieve
{
	vector<bool> is_prime;
	vi MinDiv;
	void init(int n)
	{
		is_prime.resize(n+1,true);
		MinDiv.resize(n+1);
		is_prime[0] = is_prime[1] = false;
		int i,j;
		for (i = 2; i*i <= n; i++) 
		{
	    	if (is_prime[i]) 
	    	{
	    		MinDiv[i]=i;
	        	for (j = i * i; j <= n; j += i)
	            {
	            	if(!is_prime[j]) continue;
					is_prime[j] = false;
					MinDiv[j]=i;
	    		}
	    	}
		}
	}
};

ll lcm(ll a,ll b)
{
	return (a/__gcd(a,b))*b;
}

int main()
{
	Sieve S;
	S.init(MAX);
	fastio
	test()
	{
		int n;
		cin>>n;
		vl A(n);
		take(A,0,n);
		vl B(n);
		sort(all(A));
		reverse(all(A));
		for(int i=0;i<n;i++)
		{
			ll tot = 1;
			ll num = A[i];
			int diff = 0;
			for(int j = 2;(ll)j*j<=num;j++)
			{
				if(S.is_prime[j]&&num%j==0)
				{
					int curr = 0;
					while(num%j==0)
					{
						curr++;
						num/=j;
					}
					tot*=(curr+1);
					diff++;
				}
			}
			if(num>1)
			{
				tot*=2;
				diff++;
			}
			B[i] = tot - diff;
		}
		ll currmaxi = 0, currmaxj = 1;
		ll lcmax = lcm(B[0],B[1]);
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(lcm(B[i],B[j])>lcmax)
				{
					lcmax = lcm(B[i],B[j]);
					currmaxi = i;
					currmaxj = j;
				}
			}
		}
		cout<<A[currmaxi]<<" "<<A[currmaxj]<<'\n';
	}
}	