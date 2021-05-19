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
	fastio
	test()
	{
		int n;
		// cin>>n;
		n = 2*(rng()%10000);
		string s;
		// cin>>s;
		for(int i=0;i<n;i++)
		{
			s.push_back('0' + rng()%2);
		}
		vector<vector<set<pii>>> dp(n,vector<set<pii>>(2));
		if(s[0]=='0') cout<<"NO\n";
		else
		{
			dp[0][1] = {{1,1}};
			for(int i=1;i<n;i++)
			{
				// cout<<i<<":"<<endl;
				if(s[i]=='1')
				{
					for(auto b:dp[i-1][0])
					{
						// prinp(b);
						if(b.second-1>=0 && b.first-1>=0) dp[i][0].insert({b.first-1,b.second-1});
						if(b.second+1<=n/2 && b.first+1<=n/2) dp[i][1].insert({b.first+1,b.second+1});
					}
					for(auto b:dp[i-1][1])
					{
						// prinp(b);
						if(b.second-1>=0 && b.first-1>=0) dp[i][0].insert({b.first-1,b.second-1});
						if(b.second+1<=n/2 && b.first+1<=n/2) dp[i][1].insert({b.first+1,b.second+1});
					}
				}
				else
				{
					for(auto b:dp[i-1][0])
					{
						// prinp(b);
						if(b.second-1>=0 && b.first+1<=n/2) dp[i][1].insert({b.first+1,b.second-1});
						if(b.first-1>=0 && b.second+1<=n/2) dp[i][0].insert({b.first-1,b.second+1});
					}
					for(auto b:dp[i-1][1])
					{
						// prinp(b);
						if(b.second-1>=0 && b.first+1<=n/2) dp[i][1].insert({b.first+1,b.second-1});
						if(b.first-1>=0 && b.second+1<=n/2) dp[i][0].insert({b.first-1,b.second+1});
					}
				}
			}
			if(dp[n-1][0].count({0,0}) == 0)
			{
				cout<<"NO\n";
			}
			else
			{
				cout<<"YES\n";
				pii curr = {1,1};
				string a,b;
				a.push_back(')');
				b.push_back(')');
				for(int i=n-2;i>=0;i--)
				{
					if(dp[i][0].count(curr))
					{
						a.push_back(')');
						if(s[i]=='1') b.push_back(')');
						else b.push_back('(');

						curr.first++;
						if(s[i]=='1') curr.second++;
						else curr.second--;
					}
					else
					{
						a.push_back('(');
						if(s[i]=='1') b.push_back('(');
						else b.push_back(')');

						curr.first--;
						if(s[i]=='1') curr.second--;
						else curr.second++;
					}
				}
				reverse(all(a));
				reverse(all(b));
				cout<<a<<"\n";
				cout<<b<<"\n";
			}
		}
	}
}	