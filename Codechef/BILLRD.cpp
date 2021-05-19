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
		int n,k;
		cin>>n>>k;
		int x,y;
		cin>>x>>y;
		vpii P;
		if(x==y)
		{
			cout<<n<<" "<<n<<"\n";
		}
		else if((x==n&&y==0)||(x==0&&y==n))
		{
			cout<<x<<" "<<y<<"\n";
		}
		else if(x<y)
		{
			P.push_back({x + n-y,n});
			P.push_back({P.back().second,P.back().first});
			P.push_back({n - P.back().second,0});
			P.push_back({P.back().second,P.back().first});
			prinp(P[(k-1)%4]);
		}
		else
		{
			P.push_back({n,y + n-x});
			P.push_back({P.back().second,P.back().first});
			P.push_back({0,n - P.back().first});
			P.push_back({P.back().second,P.back().first});
			prinp(P[(k-1)%4]);
		}
	}
}	