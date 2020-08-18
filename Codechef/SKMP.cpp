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
	test()
	{
		string s,p;
		cin>>s>>p;
		int np = p.length();
		int ns = s.length();
		sort(all(s));

		string x;
		vi H(26);
		for(auto c:s) H[c-'a']++;
		for(auto c:p) H[c-'a']--;

		for(int i=0;i<26;i++)
		{
			if(p[0]=='a'+i)
			{
				int j = 0;
				while(j<np&&p[j]==p[0]) j++;
				if(j==np)
				{
					// cout<<"1"<<endl;
					x += p;
					for(int j = 0;j<H[i];j++) x.push_back('a'+i);
				}
				else if(p[j]<p[0])
				{
					// cout<<"2"<<endl;
					x += p;
					for(int j = 0;j<H[i];j++) x.push_back('a'+i);
				}
				else
				{
					// cout<<"1"<<endl;
					for(int j = 0;j<H[i];j++) x.push_back('a'+i);
					x += p;
				}
			}
			else
			{
				for(int j=0;j<H[i];j++)
				{
					x.push_back('a'+i);
				}
			}		
		}
		cout<<x<<endl;
	}
	
}	