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
const int MOD = 1e9 + 7,MAX = 1e6 + 5;
const ll INF = 1e18+5;

int main()
{
	fastio
	test()
	{
		string s;
		cin>>s;
		int n = s.length();
		s = "#" + s;
		int k1,k2;
		cin>>k1>>k2;
		int numw = 0;
		set<int> Ws;
		int ans = 0;
		bool can = true;
		// cerr<<s<<endl;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='W')
			{
				numw++;
			}
			else
			{
				// cout<<"HO"<<endl;
				if(i%k1!=0 && i%k2!=0) Ws.insert(i);
				// prinv(Ws);
				if(numw>i-numw) continue;
				else if(numw-(i-numw)<2&&!Ws.empty())
				{
					ans++;
					numw++;
					s[*Ws.rbegin()] = 'W';
					Ws.erase(*Ws.rbegin());
				}
				else {can=false;break;}
			}
		}
		if(!can) cout<<-1<<endl;
		else
		{
			cout<<ans<<endl;
			s = s.substr(1,n);
			cout<<s<<'\n';
		}
	}
}	