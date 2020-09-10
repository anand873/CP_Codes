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
	test()
	{
		int n;
		cin>>n;
		string s;
		cin>>s;
		int i=1;
		while(i<n&&s[i]==s[0])
		{
			i++;
		}
		if(i==n)
		{
			cout<<(n+2)/3<<endl;
		}
		else
		{
			string snew;
			for(int pos = 0;pos<n;pos++)
			{
				snew+= s[(i+pos)%n];
			}
			s = snew;
			int ans = 0;
			int curr=1;
			// cout<<s<<endl;
			char last = s[0];
			for(int j=1;j<n;j++)
			{
				if(s[j]==last) curr++;
				else
				{
					ans += curr/3;
					curr=1;
					last = s[j];
				}
			}
			ans += curr/3;

			cout<<ans<<endl;
		}
	}
}	