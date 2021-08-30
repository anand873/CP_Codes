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
	fastio
	int k;
	cin>>k;
	string s;
	cin>>s;

	int n = s.length();

	vl NP(2*(n+1));
	for(int i=n+1;i<=2*n+1;i++)
	{
		NP[i] = 1;
	}
	map<int,int> M,N;
	int game = 0;
	for(int level = k-1;level>=0;level--)
	{
		int st = 1<<level;
		for(int i=st;i<2*st;i++)
		{
			if(s[game]=='0')
			{
				NP[i] = NP[2*i];
			}
			else if(s[game]=='1')
			{
				NP[i] = NP[2*i+1];
			}
			else
			{
				NP[i] = NP[2*i] + NP[2*i+1];
			}
			M[game] = i;
			N[i] = game;
			game++;
		}
	}

	// prinv(NP);
	int q;
	cin>>q;
	while(q--)
	{
		int p;
		char c;
		cin>>p>>c;
		p--;

		s[p] = c;

		int curr = M[p];
		// cerr<<curr<<endl;
		while(curr>=1)
		{
			if(s[N[curr]]=='1')
			{
				NP[curr] = NP[2*curr+1];
			}
			else if(s[N[curr]]=='0')
			{
				NP[curr] = NP[2*curr];
			}
			else
			{
				NP[curr] = NP[2*curr] + NP[2*curr+1];
			}
			curr /= 2;
		}
		// prinv(NP);
		cout<<NP[1]<<endl;
	}
}	