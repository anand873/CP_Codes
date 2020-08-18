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
		string s;
		cin>>s;
		int n = s.length();
		vi A(10);
		for(auto c:s)
		{
			A[c-'0']++;
		}
		int ans = 0;
		for(int i=0;i<=9;i++)
		{
			ans = max(ans,A[i]);
		}
		for(int i=0;i<=9;i++)
		{
			for(int j=0;j<=9;j++)
			{
				if(i==j) continue;
				int here = 0;
				string good;
				for(int pos=0;pos<n;pos++)
				{
					if(s[pos]=='0'+i||s[pos]=='0'+j)
					{
						if(good.length()==0)
						{
							good.push_back(s[pos]);
						}
						else
						{
							if(s[pos]!=good.back()) good.push_back(s[pos]);
						}
					}
				}
				ans = max(ans,((int)good.length()/2)*2);
			}
		}
		cout<<n-ans<<endl;
	}
}	