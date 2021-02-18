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
		int n;
		cin>>n;
		string s;
		cin>>s;
		vvi dpl(n+1,vi(2)),dpr(n+1,vi(2));
		dpl[0][0] = dpl[0][1] = 1;
		dpr[n][0] = dpr[n][1] = 1;
		for(int i=1;i<=n;i++)
		{
			if(s[i-1]=='L')
			{
				dpl[i][0] = dpl[i-1][1] + 1;
				dpl[i][1] = 1;
			}
			else
			{
				dpl[i][0] = 1;
				dpl[i][1] = dpl[i-1][0] + 1;
			}
		}
		for(int i=n-1;i>=0;i--)
		{
			if(s[i]=='R')
			{
				dpr[i][0] = dpr[i+1][1] + 1;
				dpr[i][1] = 1;
			}
			else
			{
				dpr[i][0] = 1;
				dpr[i][1] = dpr[i+1][0] + 1;
			}
		}

		for(int i=0;i<=n;i++)
		{
			cout<<dpl[i][0]+dpr[i][0] - 1<<" ";
		}
		cout<<"\n";

	}
}