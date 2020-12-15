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

bool cmp(pii x,pii y)
{
	if(x.second==y.second)
	{
		return x.first<y.first;
	}
	else return x.second<y.second;
}

int main()
{
	int n,m;
	cin>>n>>m;
	ll sx,sy,fx,fy;
	cin>>sx>>sy>>fx>>fy;

	vpii X,Y;
	for(int i=0;i<m;i++)
	{
		cin>>X[i].first>>X[i].second;
	}
	Y = X;
	sort(all(X));
	sort(all(Y),cmp);
	map<pii,pii> MxN,MyN;
	
}	