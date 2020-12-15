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

int main()
{
	test()
	{
		int n,q;
		cin>>n>>q;
		vi A(n+2);
		take(A,1,n);
		A[0] = -n-1;
		A[n+1] = -n-1;
		ll ans = 0;
		set<int> Pos;
		set<int> Neg;
		for(int i=1;i<=n;i++)
		{
			if(A[i]>A[i-1]&&A[i]>A[i+1]) {ans += A[i];Pos.insert(A[i]);}
			if(A[i]<A[i-1]&&A[i]<A[i+1]) {ans -= A[i];Neg.insert(A[i]);}
		}
		cout<<ans<<endl;
		while(q--)
		{
			int u,v;
			cin>>u>>v;
			swap(A[u],A[v]);
			ll diff = 0;
			for(int i=u-1;i<=u+1;i++)
			{
				if(i<=0) continue;
				if(i>n) continue;
				if(A[i]>A[i-1]&&A[i]>A[i+1])
				{
					if(Neg.count(A[i]))
					{
						Neg.erase(A[i]);
						Pos.insert(A[i]);
						diff += 2*A[i];
					}
					else if(!Pos.count(A[i]))
					{
						Pos.insert(A[i]);
						diff += A[i];
					}
				}
				else if(A[i]<A[i-1]&&A[i]<A[i+1])
				{
					if(Pos.count(A[i]))
					{
						Pos.erase(A[i]);
						Neg.insert(A[i]);
						diff -= 2*A[i];
					}
					else if(!Neg.count(A[i]))
					{
						Neg.insert(A[i]);
						diff -= A[i];
					}
				}
				else
				{
					if(Pos.count(A[i]))
					{
						Pos.erase(A[i]);
						diff -= A[i];
					}
					else if(Neg.count(A[i]))
					{
						Neg.erase(A[i]);
						diff += A[i];
					}
				}
			}
			for(int i=v-1;i<=v+1;i++)
			{
				if(i<=u+1) continue;
				if(i<=0) continue;
				if(i>n) continue;
				if(A[i]>A[i-1]&&A[i]>A[i+1])
				{
					if(Neg.count(A[i]))
					{
						Neg.erase(A[i]);
						Pos.insert(A[i]);
						diff += 2*A[i];
					}
					else if(!Pos.count(A[i]))
					{
						Pos.insert(A[i]);
						diff += A[i];
					}
				}
				else if(A[i]<A[i-1]&&A[i]<A[i+1])
				{
					if(Pos.count(A[i]))
					{
						Pos.erase(A[i]);
						Neg.insert(A[i]);
						diff -= 2*A[i];
					}
					else if(!Neg.count(A[i]))
					{
						Neg.insert(A[i]);
						diff -= A[i];
					}
				}
				else
				{
					if(Pos.count(A[i]))
					{
						Pos.erase(A[i]);
						diff -= A[i];
					}
					else if(Neg.count(A[i]))
					{
						Neg.erase(A[i]);
						diff += A[i];
					}
				}
			}
			ans += diff;
			cout<<ans<<'\n';

		}
	}
}	