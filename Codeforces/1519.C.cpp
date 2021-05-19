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
const int MOD = 1e9+7,MAX = 2e5+5;
const ll INF = 1e18+5;

int main()
{
	fastio
	vector<set<int>> Fac(MAX+1);
	for(int i=2;i<=MAX;i++)
	{
		for(int j=i;j<=MAX;j+=i)
		{
			Fac[j].insert(i);
		}
	}
	test()
	{
		int n;
		cin>>n;
		vi U(n+1),S(n+1);
		take(U,1,n);
		take(S,1,n);
		ll tot = 0;
		map<int,vi> M_Uni;
		for(int i=1;i<=n;i++)
		{
			tot +=  S[i];
			M_Uni[U[i]].push_back(S[i]);
		}
		for(auto &m:M_Uni)
		{
			sort(all(m.second));
			reverse(all(m.second));
		}
		vl dp(n+1);
		dp[1] = tot;
		for(auto m:M_Uni)
		{
			// prinv(m.second);
			int sz = m.second.size();
			vl PS(sz+1);
			for(int i=1;i<=sz;i++)
			{
				PS[i] = PS[i-1] + m.second[i-1];
				auto it = Fac[i].upper_bound(sz-i);
				while(it!=Fac[i].end())
				{
					dp[*it]+=PS[i];
					it++;
				}
			}

		}
		for(int i=1;i<=n;i++) cout<<dp[i]<<" ";
		cout<<'\n';
	}
}	