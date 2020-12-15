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
		int n,k;
		cin>>n>>k;
		string s;
		cin>>s;

		set<pair<int,int>> S;
		int i=0;
		while(i<n&&s[i]=='L') i++;
		while(i<n)
		{
			while(i<n&&s[i]=='W') i++;
			int st=i;
			while(i<n&&s[i]=='L') i++;
			if(i!=n) S.insert({i-st,st});
		}
		for(auto gap:S)
		{
			// prinp(gap);
			if(gap.first<=k)
			{
				int st = gap.second;
				for(int i=st;i<st+gap.first;i++)
				{
					s[i]='W';
				}
				k-=gap.first;
			}
			else
			{
				int st = gap.second;
				for(int i=st;i<st+k;i++)
				{
					s[i]='W';
				}
				k=0;
			}
		}
		if(k)
		{
			for(int i=0;i<n;i++)
			{
				if(s[i]=='W')
				{
					for(int j=i-1;j>=max(0,i-k);j--)
					{
						s[j]='W';
					}
					k = max(0,k-i);
					break;
				}
			}
		}
		if(k)
		{
			for(int i=n-1;i>=0;i--)
			{
				if(s[i]=='W')
				{
					for(int j=i+1;j<n&&k;j++)
					{
						s[j]='W';
						k--;
					}
					break;
				}
			}
		}
		if(k)
		{
			for(int i=0;i<min(n,k);i++) s[i]='W';
		}
		// cout<<s<<endl;
		int cost=0;
		cost += (s[0]=='W');
		for(int i=1;i<n;i++)
		{
			if(s[i]=='W')
			{
				cost++;
				cost += (s[i-1]=='W');
			}
		}
		cout<<cost<<endl;
	}
}	