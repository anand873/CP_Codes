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
		string s,p;
		cin>>s>>p;
		string news,newp;
		news=s;
		newp=p;
		sort(all(news));
		sort(all(newp));
		if(news!=newp)
		{
			cout<<"No"<<endl;
		}
		else
		{
			vi dp(n,-1);
			for(int i=n-2;i>=0;i--)
			{
				if(s[i+1]=='0') dp[i]=i+1;
				else dp[i]=dp[i+1];
			}
			bool can=true;
			int curr = 0;
			for(int i=0;i<n;i++)
			{
				curr = max(curr,i);
				if(s[i]==p[i]) continue;
				else if(s[i]=='0'&&p[i]=='1')
				{
					can=false;
					break;
				}
				else
				{
					if(dp[curr]==-1) {can=false;break;}
					else
					{
						swap(s[i],s[dp[curr]]);
						curr = dp[curr];
					}
				}
			}
			if(can) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}


	}
}	