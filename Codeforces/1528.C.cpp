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
const int MOD = 998244353,MAX = 1e6+5;
const ll INF = 1e18+5;

vi Tin,Tout;
vvi A,B;
int curr;
void dfs(int u)
{
	Tin[u] = curr++;
	for(auto v:B[u])
	{
		dfs(v);
	}
	Tout[u] = curr++;
}

set<pii> S;
int ans;

void dfsA(int u)
{
	pii Tim = {Tout[u],Tin[u]};
	pii tor = {-1,-1};
	if(S.empty()) S.insert(Tim);
	else
	{
		auto s = S.lower_bound(Tim);
		auto ss = s;
		if(s==S.begin())
		{
			if(s->second>Tim.first)
			{
				S.insert(Tim);
			}
			else
			{
				tor = *s;
				S.erase(tor);
				S.insert(Tim);
			}
		}
		else
		{
			ss--;
			if(s==S.end())
			{
				if(ss->first < Tim.second)
				{
					S.insert(Tim);
				}
			}
			else
			{
				if(s->second > Tim.first && ss->first < Tim.second)
				{
					S.insert(Tim);
				}
				else if(s->second < Tim.first)
				{
					tor = *s;
					S.erase(tor);
					S.insert(Tim);
				}
			}
			

		}
	}
	for(auto v:A[u])
	{
		dfsA(v);
	}
	
	ans = max(ans,(int)S.size());
	
	if(tor==make_pair(-1,-1))
	{
		if(S.count(Tim)) S.erase(Tim);
	}
	else
	{
		S.erase(Tim);
		S.insert(tor);
	}
}

int main()
{
	fastio
	test()
	{
		int n;
		cin>>n;
		Tin.resize(n+1);
		Tout.resize(n+1);
		ans = 1;
		curr = 0;
		A.resize(n+1);B.resize(n+1);
		for(int i=2;i<=n;i++)
		{
			int p;
			cin>>p;
			A[p].push_back(i);
		}
		for(int i=2;i<=n;i++)
		{
			int p;
			cin>>p;
			B[p].push_back(i);
		}

		dfs(1);

		dfsA(1);
		cout<<ans<<'\n';

		Tin.clear();
		Tout.clear();
		S.clear();
		A.clear();
		B.clear();
	}
}	 