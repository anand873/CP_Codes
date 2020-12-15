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
	int a,b;
	cin>>a>>b;
	if(a>b) swap(a,b);
	for(int x=1;x<a;x++)
	{
		int y = sqrt(a*a - x*x);
		if(x*x+y*y==a*a)
		{
			// (x,y)
			int u,v;
			u = x*b/a;
			v = y*b/a;
			if(u*u+v*v==b*b)
			{
				cout<<"YES"<<endl;
				cout<<0<<" "<<0<<endl;
				cout<<x<<" "<<y<<endl;
				if(y!=u) cout<<-v<<" "<<u<<endl;
				else cout<<v<<" "<<-u<<endl;
				return 0;
			}
		}
	}
	cout<<"NO"<<endl;
}	