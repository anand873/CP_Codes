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
		int n;
		cin>>n;
		vvi RC(n+1,vi(2));
		for(int i=1;i<=n;i++) cin>>RC[i][0];
		for(int i=1;i<=n;i++) cin>>RC[i][1];
		RC[0][0] = 1;
		RC[0][1] = 1;
		sort(all(RC));
		int cst = 0;
		for(int i=1;i<=n;i++)
		{
			int rdif = RC[i][0] - RC[i-1][0];
			int cdif = RC[i][1] - RC[i-1][1];
			if(rdif == cdif) 
			{
				if((RC[i][0] + RC[i][1])%2) cst+=0;
				else cst += rdif;
			}
			else
			{
				if((RC[i-1][0]+RC[i-1][1])%2) cst += (rdif - cdif + 1)/2;
				else cst += (rdif - cdif)/2;
			}
			// cout<<RC[i][0]<<" "<<RC[i][1]<<" "<<cst<<endl;
		} 
		cout<<cst<<endl;
	}
}	