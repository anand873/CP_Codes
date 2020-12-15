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
		vector<string> V(n);
		take(V,0,n);
		vvi row(n,vi(10,-1));
		vvi col(n,vi(10,-1));
		vi Fr(10,-1),Fc(10,-1);
		vi Nr(10,n),Nc(10,n);
		for(int r=0;r<n;r++)
		{
			for(int c=0;c<n;c++)
			{
				row[r][V[r][c]-'0'] = c;
				Fc[V[r][c]-'0'] = max(Fc[V[r][c]-'0'],c);
				Nc[V[r][c]-'0'] = min(Nc[V[r][c]-'0'],c);
			}
		}
		for(int c=0;c<n;c++)
		{
			for(int r=0;r<n;r++)
			{
				col[c][V[r][c]-'0'] = r;
				Fr[V[r][c]-'0'] = max(Fr[V[r][c]-'0'],r);
				Nr[V[r][c]-'0'] = min(Nr[V[r][c]-'0'],r);
			}
		}
		vi Ans(10,0);
		for(int r=0;r<n;r++)
		{
			for(int c=0;c<n;c++)
			{
				int x = V[r][c]-'0';
				Ans[x] = max({Ans[x],max(0,Fr[x]-r)*max(c,n-1-c),max(0,r-Nr[x])*max(c,n-1-c)});
				Ans[x] = max({Ans[x],max(0,Fc[x]-c)*max(r,n-1-r),max(0,c-Nc[x])*max(r,n-1-r)});

			}
		}
		prinv(Ans);

	}
}
	