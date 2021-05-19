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
int MOD = 1e9+7,MAX = 2e5+5;
const ll INF = 1e18+5;

int main()
{
	test()
	{
		int n;
		cin>>n;
		string s;
		cin>>s;
		vl fdp(n);
		vl bdp(n);
		fdp[0]=0;
		bdp[n-1]=0;

		ll cnt = 0;
		int last = -1;
		if(s[0]=='*') {cnt++;last=0;}
		for(int i=1;i<n;i++)
		{
			fdp[i] = fdp[i-1];
			if(s[i]=='*')
			{
				// fdp[i] += (i-last-1)*cnt;
				cnt++;
				last = i;
			}
			else fdp[i] += cnt;
		}

		cnt = 0;
		last = n;
		if(s[n-1]=='*') {cnt++;last=n-1;}
		for(int i=n-2;i>=0;i--)
		{
			bdp[i] = bdp[i+1];
			if(s[i]=='*')
			{
				// bdp[i] += (last-i-1)*cnt;
				cnt++;
				last=i;
			}
			else bdp[i] += cnt;
		}
		// prinv(fdp);
		// prinv(bdp);
		ll ans = INF;
		ans = min({ans,fdp[n-1],bdp[0]});
		for(int i=0;i<n-1;i++)
		{
			ans = min(ans,fdp[i]+bdp[i+1]);
		}
		cout<<ans<<endl;
	}
}