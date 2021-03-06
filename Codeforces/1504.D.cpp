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
	int n;
	cin>>n;
	set<pii> B,G;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if((i+j)%2) B.insert({i,j});
			else G.insert({i,j});
		}
	}
	for(int i=0;i<n*n;i++)
	{
		int a;
		cin>>a;
		if(a==1)
		{
			if(!B.empty())
			{
				pii p = *B.begin();
				B.erase(p);
				cout<<2<<" "<<p.first<<" "<<p.second<<endl;
			}
			else
			{
				pii p = *G.begin();
				G.erase(p);
				cout<<3<<" "<<p.first<<" "<<p.second<<endl;
			}
		}
		else if(a==2)
		{
			if(!G.empty())
			{
				pii p = *G.begin();
				G.erase(p);
				cout<<1<<" "<<p.first<<" "<<p.second<<endl;
			}
			else
			{
				pii p = *B.begin();
				B.erase(p);
				cout<<3<<" "<<p.first<<" "<<p.second<<endl;
			}
		}
		else
		{
			if(!G.empty())
			{
				pii p = *G.begin();
				G.erase(p);
				cout<<1<<" "<<p.first<<" "<<p.second<<endl;
			}
			else
			{
				pii p = *B.begin();
				B.erase(p);
				cout<<2<<" "<<p.first<<" "<<p.second<<endl;
			}
		}
	}
}	