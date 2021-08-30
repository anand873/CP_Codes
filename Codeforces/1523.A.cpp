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
		string s;
		cin>>s;
		s += "0";
		reverse(all(s));
		s += "0";
		reverse(all(s));
		for(int x=0;x<min(n,m);x++)
		{
			string news = s;
			for(int i=1;i<s.length()-1;i++)
			{
				// cout<<s<<endl;
				if(s[i]=='1')
				{
					news[i] = '1';
				}
				else if((s[i-1]-'0') + (s[i+1]-'0') == 1)
				{
					news[i] = '1';
				}
				else news[i] = '0';
			}
			s = news;
		}
		cout<<s.substr(1,n)<<endl;
	}
}	