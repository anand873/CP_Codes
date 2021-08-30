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
		int n,m;
		cin>>n>>m;
		vector<string> V(n);
		take(V,0,n);
		int r = -1, b = -1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(V[i][j]=='R'&&r==-1)
				{
					r = (i+j)%2;
				}
				else if(V[i][j]=='W' && b==-1)
				{
					b = (i+j)%2;
				}
			}
		}
		if(r==-1 || b==-1 || r!=b)
		{
			if(r==-1 && b==-1)
			{
				r = 0;
				b = 1;
			}
			else if(r==-1)
			{
				r = 1-b;
			}
			else if(b==-1)
			{
				b = 1-r;
			}

			bool can = true;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					if(V[i][j]=='R' && (i+j)%2 != r) can = false;
					else if(V[i][j]=='W' && (i+j)%2 != b) can = false;
				}
			}
			if(!can) {cout<<"NO\n";continue;}
			cout<<"YES\n";
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					if((i+j)%2 == r) cout<<"R";
					else cout<<"W";
				}
				cout<<"\n";
			}

		}
		else cout<<"NO\n";
	}
}	