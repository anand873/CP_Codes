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
#define KStest() int t,t1;cin>>t;t1=t;while(t-AC-)
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
		vi A(n+1);
		take(A,1,n);
		vvi X(n+1,{0});
		for(int i=1;i<=n;i++)
		{
			X[A[i]].push_back(i);
		}
		for(int i=0;i<=n;i++) X[i].push_back(n+1);
		vector<int> M(n+2,n+1);
		for(int i=1;i<=n;i++)
		{
			int ans = 0;
			for(int j=1;j<X[i].size();j++)
			{
				ans = max(X[i][j]-X[i][j-1],ans);
			}
			M[ans]=min(M[ans],i);
		}
		for(int i=1;i<=n;i++)
		{
			M[i] = min(M[i-1],M[i]);
		}
		for(int i=1;i<=n;i++)
		{
			if(M[i]==n+1) cout<<-1<<" ";
			else cout<<M[i]<<" ";
		}
		cout<<endl;

	}
}	