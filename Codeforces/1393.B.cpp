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
const int MOD = 1e9+7,MAX = 1e6+5;
const ll INF = 1e18+5;

int main()
{
	int n;
	cin>>n;
	vector<int> V(9);

	map<int,int> M;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		M[x]++;
	}
	for(auto m:M)
	{
		V[min(m.second,8)]++;
	}

	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		char c;
		int x;
		cin>>c>>x;
		if(c=='+')
		{
			V[min(8,M[x])]--;
			M[x]++;
			V[min(8,M[x])]++;
		}
		else
		{
			V[min(8,M[x])]--;
			M[x]--;
			V[min(8,M[x])]++;
		}

		int more2 = 0,more4=0,more6=0,more8=0;

		for(int i=0;i<=8;i++)
		{
			if(i>=2) more2+=V[i];
			if(i>=4) more4+=V[i];
			if(i>=6) more6+=V[i];
			if(i>=8) more8+=V[i]; 
		}
		if(more8>=1|| (more4>=2) || (more4==1&&more2>=3) || (more6==1&&more2>=2)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;

	}


}	