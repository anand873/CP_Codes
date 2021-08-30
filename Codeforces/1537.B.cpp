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
		ll n,m,i,j;
		cin>>n>>m>>i>>j;

		set<pii> E = {{1,1},{n,1},{n,m},{1,m}};

		if(E.count({i,j})==1)
		{
			E.erase({i,j});
			// cout<<E.size()<<endl;
			if(E.empty())
			{
				cout<<i<<" "<<j<<" "<<i<<" "<<j<<endl;
			}
			else
			{
				cout<<E.begin()->first<<" "<<E.begin()->second<<" "<<E.rbegin()->first<<" "<<E.rbegin()->second<<endl;
			}
		}
		else
		{
			ll maxx = 0;
			pii m1,m2;

			for(auto x:E)
			{
				for(auto y:E)
				{
					ll temp = 0;
					temp = abs(x.first-i)+abs(x.second-j) + abs(x.first-y.first) + abs(x.second-y.second) + abs(y.first-i) + abs(y.second-j);
					if(temp >= maxx)
					{
						m1 = x;
						m2 = y;
						maxx = temp;
					}
				}
			}
			cout<<m1.first<<" "<<m1.second<<" "<<m2.first<<" "<<m2.second<<endl;
		}
			

	}
}	