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
		int n;
		cin>>n;
		string s;
		cin>>s;
		int ans=0;
		vi X;
		int curr=1;
		for(int i=1;i<n;i++)
		{
			if(s[i]!=s[i-1])
			{
				X.push_back(curr);
				curr=1;
			}
			else
			{
				curr++;
			}
		}
		X.push_back(curr);
		vpii Y;
		for(int i=0;i<X.size();i++)
		{
			if(X[i]>1)
			{
				Y.push_back({X[i],i+1});
			}
		}
		int remdone=0;
		int done=0;
		for(int i=0;i<Y.size();i++)
		{
			int idx = Y[i].second;
			int val = Y[i].first;
			int how = min((idx-done-1),val-1);
			// cout<<idx<<" "<<val<<endl;
			if(val>=how+2)
			{
				ans += how+1;
				done += how+1;
				remdone += how+val;
			}
			else
			{
				ans += how;
				done += how;
				remdone += 2*how;
			}
			// cout<<done<<endl;
		}
		ans += (n-remdone+1)/2;
		cout<<ans<<endl;

	}
}	