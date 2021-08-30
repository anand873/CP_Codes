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
const int MOD = 1e9+7,MAX = 2e5+5;
const ll INF = 1e18+5;

int main()
{
	test()
	{
		int h,w;
		cin>>h>>w;
		vvi M(h,vi(w));
		for(int i=0;i<w;i+=2)
		{
			M[0][i] = 1;
		}

		for(int i=2;i<h-2;i++)
		{
			if(M[i-1][0]==0) M[i][0] = 1;
			if(M[i-1][w-1]==0) M[i][w-1] = 1;
		}

		for(int i=0;i<w;i+=2)
		{
			M[h-1][i] = 1;
		}
		
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
				cout<<M[i][j];
			}
			cout<<endl;
		}

	}
}	