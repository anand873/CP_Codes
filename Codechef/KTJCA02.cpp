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
const int MOD = 1e9+7,MAX = 1e5+5;
const ll INF = 1e18+5;

int main()
{
	test()
	{
		int n;
		cin>>n;
		vi C(n+1);
		take(C,1,n);
		vector<bitset<MAX>> N(n+1);
		for(int i=1;i<=n;i++)
		{
			N[i]= 1;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				int maxw = i^j;
				bitset<MAX> X = 1;
				for(int edge = 0;edge<maxw;edge++)
				{
					X |= X<<1;
				}
				N[i] |= X;
				N[j] |= X;
			}
		}
		bool can = true;
		for(int i=1;i<=n;i++)
		{
			if(N[i][C[i]]==0) can = false;
		}
		if(can) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}	