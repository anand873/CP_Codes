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
int MOD = 1e9+7,MAX = 5e5+5;
const ll INF = 1e18+5;

set<vector<string>> WD,I;

bool windraw(vector<string> V)
{
	int emp = 0;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(V[i][j]=='_') emp++;
		}
	}
	if(emp==0) return true;

	for(int i=0;i<3;i++)
	{
		if(V[i][0]!='_' && V[i][0]==V[i][1] && V[i][1]==V[i][2]) return true;
		if(V[0][i]!='_' && V[0][i]==V[1][i] && V[1][i]==V[2][i]) return true;
	}
	if(V[1][1]!='_' && V[1][1]==V[2][2]&&V[2][2]==V[0][0]) return true;
	if(V[1][1]!='_' && V[0][2]==V[1][1] && V[1][1]==V[2][0]) return true;
	return false;
}

void runSim(vector<string> S,int p)
{
	I.insert(S);
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(S[i][j]=='_')
			{
				vector<string> X = S;
				X[i][j] = p?'O':'X';
				if(WD.count(X)||I.count(X)) continue;
				else if(windraw(X))
				{
					WD.insert(X);
				}
				else
				{
					runSim(X,p^1);
				}
			}
		}
	}
}

int main()
{
	fastio
	vector<string> S = {"___","___","___"};
	runSim(S,0);
	// for(auto v:WD)
	// {
	// 	for(int i=0;i<3;i++) cout<<v[i]<<endl;
	// 	cout<<endl;
	// }
	test()
	{
		vector<string> A(3);
		take(A,0,3);
		// for(int i=0;i<3;i++) cout<<A[i]<<endl;
		// cout<<WD.count(A)<<endl;
		if(WD.count(A)) cout<<1<<'\n';
		else if(I.count(A)) cout<<2<<'\n';
		else cout<<3<<'\n';
	}
}