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
const int MOD = 1e9+7,MAX = 1e5+5;
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
		for(int i=2;i<=n;i++) if(is_prime[i]) MinDiv[i]=i;
	}
};	

int main()
{
	fastio
	Sieve S;
	S.init(MAX);

	int n,q;
	cin>>n>>q;
	vi A(n+1);
	take(A,1,n);
	map<int,int> M;

	vector<vector<int>> P_F(n+1);
	vector<int> Best(n+1);
	for(int st=1;st<=n;st++)
	{
		Best[st] = Best[st-1];
		int best = Best[st];
		for(int i=Best[st]+1;i<=n;i++)
		{
			bool good = true;
			int val = A[i];
			while(val>1)
			{
				int md = S.MinDiv[val];
				P_F[i].push_back(md);
				if(M[md]>0) good = false;
				while(val%md==0)
				{
					val/=md;
				}
			}
			if(good)
			{
				best = i;
				for(auto p:P_F[i]) M[p]++;
			}
			else break;
		}
		Best[st] = best;
		for(auto p:P_F[st])
		{
			M[p]--;
		}
	}
	// cout<<"Done Jump"<<endl;
	vector<vector<int>> dp(n+1,vi(20));
	for(int i=1;i<=n;i++)
	{
		dp[i][0] = Best[i];
	}
	for(int b=1;b<20;b++)
	{
		for(int i=1;i<=n;i++)
		{
			dp[i][b] = dp[min(n,dp[i][b-1]+1)][b-1];
		}
	}
	// for(int i=1;i<=n;i++)
	// {
	// 	for(int b=0;b<20;b++)
	// 	{
	// 		cout<<dp[i][b]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	// cout<<"Take Query"<<endl;
	for(int i=0;i<q;i++)
	{
		int l,r;
		cin>>l>>r;
		int ans = -1;
		int low=1,high = n;
		while(low<=high)
		{
			int mid = low + (high-low)/2;

			int curr = l-1;
			for(int i=0;i<20;i++)
			{
				if((mid>>i)&1)
				{
					curr = dp[min(n,curr+1)][i];
				}
			}
			if(curr>=r)
			{
				ans = mid;
				high = mid-1;
			}
			else
			{
				low = mid+1;
			}
		}
		cout<<ans<<"\n";
	}


}	