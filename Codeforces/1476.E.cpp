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

vvi A;
bool can = true;
vi TS;
vi vis,inStack;
void dfs(int x, int parent) 
{
    vis[x] = true;
    inStack[x] = true;
    for(auto v:A[x]) 
    {
        if (vis[v] && inStack[v]) 
        {
            can = false;
            return;
        }
        if(!vis[v]) 
        {
            dfs(v, x);
        }
    }
    inStack[x] = false;
    TS.push_back(x);
}

int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	A.resize(n+1);
	vector<string> P(n+1);
	map<string,int> Sp;
	take(P,1,n);
	for(int i=1;i<=n;i++) Sp[P[i]] = i;
	
	vis.resize(n+1);
	inStack.resize(n+1);

	vector<int> MT(m+1);
	vector<string> S(m+1);

	for(int i=1;i<=m;i++)
	{
		cin>>S[i]>>MT[i];
		set<string> X;
		X.insert("");
		for(int j=0;j<k;j++)
		{
			set<string> XX;
			for(auto x:X)
			{
				XX.insert(x+'_');
				XX.insert(x+S[i][j]);
			}
			X = XX;
		}
		if(X.count(P[MT[i]])==0) {can = false;break;}
		for(auto x:X)
		{
			if(Sp.find(x)==Sp.end() || Sp[x]==MT[i]) continue;
			else
			{
				A[MT[i]].push_back(Sp[x]);
			}
		}
	}
	// for(int i=1;i<=n;i++)
	// {
	// 	prinv(A[i]);
	// }
	for(int i=1;i<=n;i++)
	{
		if(!vis[i]) dfs(i,-1);
	}
	if(can)
	{
		cout<<"YES"<<endl;
		reverse(all(TS));
		prinv(TS);
	}
	else cout<<"NO"<<endl;


}