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

vector<set<int>> V;
vi vis;
int n;

int main()
{
	cin>>n;
	V.resize(n+1);
	vis.resize(n+1);
	vis[0]=true;
	set<int> S;
	for(int i=1;i<=n;i++)
	{
		S.insert(i);
	}

	int query = 0;
	while(S.size()>=1)
	{
		int u = *S.begin();
		S.erase(u);
		query++;
		assert(query<=(n+1)/2);
		cout<<"? "<<u<<endl;
		vvi D(n+1);
		for(int i=1;i<=n;i++)
		{
			int d;
			cin>>d;
			if(!vis[i]) D[d].push_back(i);
		}

		int dis = 1;
		int curr = u;
		while(D[dis].size()==1)
		{
			S.erase(D[dis].back());
			V[curr].insert(D[dis].back());
			curr = D[dis].back();
			vis[curr] = true;
			dis++;
		}
		if(dis==1)
		{
			for(auto d:D[1])
			{
				S.erase(d);
				V[curr].insert(d);
			}
		}
		else
		{
			for(auto d:D[dis])
			{
				S.erase(d);
				V[curr].insert(d);
			}
		}
	}

	cout<<"!"<<endl;
	for(int i=1;i<=n;i++)
	{
		for(auto v:V[i])
		{
			if(v < i && V[v].count(i)) continue;
			cout<<i<<" "<<v<<endl;
		}
	}
}	