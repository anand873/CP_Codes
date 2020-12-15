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
	Sieve S;
	S.init(MAX);
	test()
	{
		ll n;
		cin>>n;
		ll tempn = n;
		map<ll,int> M;
		for(int i=2;(ll)i*i<=n;i++)
		{
			if(S.is_prime[i])
			{
				while(tempn%i==0)
				{
					tempn/=i;
					M[i]++;
				}
			}
		}
		if(tempn!=1) M[tempn]++;
		// for(auto m:M) prinp(m);
		vector<pair<int,ll>> V;
		for(auto m:M)
		{
			V.push_back({m.second,m.first});
		}
		sort(all(V));
		reverse(all(V));
		int k = V[0].first;
		vl Ans(k,1);

		for(int i=k-1;i>=0;i--)
		{
			// for(auto m:M) prinp(m);
			vl TE;
			for(auto &m:M)
			{
				Ans[i]*=m.first;
				m.second--;
				if(m.second==0) TE.push_back(m.first);
			}
			for(auto te:TE) M.erase(te);
		}
		cout<<k<<endl;
		prinv(Ans);

	}
}	