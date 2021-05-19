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
const int MOD = 1e9+7,MAX = 1e6+5;
const ll INF = 1e18+5;

ll powN(ll a,ll p)
{
	if(p==0) return 1;
	ll z=powN(a,p/2);
	z=(z*z)%MOD;
	if(p%2) z=(z*a)%MOD;
	return z;
}

int main()
{
	test()
	{
		int n;
		cin>>n;
		vi A(n);
		take(A,0,n);
		ll ans = 0;
		int mex = n+1;
		// Calc Mex;
		set<int> SS;
		for(int i=0;i<n;i++)
		{
			SS.insert(A[i]);
		}
		for(int i=0;i<=n+1;i++)
		{
			if(SS.count(i)==0) {mex = i;break;}
		}
		if(mex==0)
		{
			cout<<powN(2,n-1)<<endl;
		}
		else
		{
			while(A.back()>mex) A.pop_back();
			reverse(all(A));
			while(A.back()>mex) A.pop_back();
			reverse(all(A));
			int n = A.size();
			// cout<<mex<<endl;
			vi dp(n);
			set<int> S;
			if(A[0]<mex) S.insert(A[0]);
			if(S.size()==mex)
			{
				S.clear();
				dp[0] = 1;
			}
			int last = -1;
			for(int i=1;i<n;i++)
			{
				if(A[i]<mex) S.insert(A[i]);
				if(S.size()==mex)
				{
					S.clear();
					if(dp[i-1]==0)
					{
						last = i;
						dp[i] = 1;
						
						continue;
					}
					for(int j=i;j>last;j--)
					{
						if(A[j]<mex) S.insert(A[j]);
						if(S.size()==mex)
						{
							dp[i] = ((ll)(j-last+1)*dp[i-1])%MOD;
							break;
						}
					}
					last = i;
					S.clear();
				}
				else dp[i] = dp[i-1];
			}
			prinv(dp);
			cout<<dp[n-1]<<endl;
		}
		
	}	
}	