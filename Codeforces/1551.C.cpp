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
#define test() int q;cin>>q;while(q--)
#define all(v) v.begin(),v.end()
#define prinp(p) cout<<p.first<<" "<<p.second<<endl
#define prinv(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int in=f;in<f+n;in++) cin>>V[in]
#define what(x) cerr<<#x<<" = "<<x<<endl
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 1e9,MAX = 3e5+5;
const ll INF = 1e18+5;

int main()
{
	test()
	{
		int n;
		cin>>n;
		vector<string> V(n);
		take(V,0,n);
		int ans = 0;
		int totlet = 0;
		for(auto s:V)
		{
			totlet += s.length();
		}

		for(int ps=0;ps<5;ps++)
		{
			vi HM(n);
			for(int i=0;i<n;i++)
			{
				for(auto c:V[i])
				{
					if(c==('a'+ps)) HM[i]++;
					else HM[i]--;
				}
			}
			sort(all(HM));
			reverse(all(HM));
			int temp = 0;
			int sum = 0;
			for(int i=0;i<n;i++)
			{
				sum += HM[i];
				if(sum > 0)
				{
					temp++;
				}
				else break;
			}
			ans = max(ans,temp);
		}
		cout<<ans<<endl;

	}
}	