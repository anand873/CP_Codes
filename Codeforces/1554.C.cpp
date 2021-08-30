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
#define all(v) v.begin(),v.end()
#define prinp(p) cout<<p.first<<" "<<p.second<<endl
#define prinv(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int in=f;in<f+n;in++) cin>>V[in]
#define what(x) cerr<<#x<<" = "<<x<<endl
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1e9+7,MAX = 1e6+5;
const ll INF = 1e18+5;

int main()
{
	test()
	{
		ll n,m;
		cin>>n>>m;
		vi M(32),N(32);
		for(int i=0;i<32;i++)
		{
			M[i] = (m>>i)&1;
			N[i] = (n>>i)&1;
		}

		for(int i=31;i>=0;i--)
		{
			if(M[i]==0 && N[i]==0) continue;
			else if(M[i]==1 && N[i]==0) continue;
			else if(M[i]==1 && N[i]==1)
			{
				M[i] = 0;
			}
			else
			{
				for(int j=i;j>=0;j--) M[j] = 0;
				break;
			}
		}
		int ans = 0;
		for(int i=0;i<32;i++)
		{
			ans += M[i] * (1<<i);
		}
		if((ans^n) == m) 
		{
			for(int i=0;i<32;i++)
			{
				if(((m>>i)&1)==1 && ((n>>i)&1)==0)
				{
					M[i] = 0;
				}
				else if(((m>>i)&1)==0 && ((n>>i)&1)==0)
				{
					M[i] = 1;
					break;
				}
			}
			// prinv(M);
			ans = 0;
			for(int i=0;i<32;i++)
			{
				ans += M[i] * (1<<i);
			}
			cout<<ans<<endl;
		}
		else cout<<ans<<endl;
	}
}	