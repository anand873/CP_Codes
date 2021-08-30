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
const int MOD = 1e9,MAX = 5e5+5;
const ll INF = 1e18+5;

int main()
{
	test()
	{
		string s;
		cin>>s;
		int q = 0;
		int n = s.length();

		for(auto c:s) if(c=='?') q++;

		int ans = 10;
		for(int msk=0;msk<(1<<q);msk++)
		{
			string ss = s;
			int m = msk;
			for(int i=0;i<n;i++)
			{
				if(ss[i]=='?')
				{
					ss[i] = '0' + (m%2);
					m/=2;
				}
			}
			// cout<<ss<<endl;
			vi T(2);
			for(int i=0;i<n;i++)
			{
				if(ss[i]=='1')
				{
					T[i%2]++;
				}

				int team0 = T[0];
				int team1 = T[1];
				int rem0 = 4 - i/2;
				int rem1 = 5 - (i+1)/2;

				if(team0 > team1)
				{
					swap(team0,team1);
					swap(rem0, rem1);
				}
				if(team0 + rem0 < team1) ans = min(ans,i+1);
			}
		}
		cout<<ans<<endl;
	}
}	