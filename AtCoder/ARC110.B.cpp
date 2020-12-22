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
	int n;
	cin>>n;
	string t;
	cin>>t;
	if(t=="0")
	{
		cout<<1ll*100000*100000<<endl;
		return 0;
	}
	else if(t=="1")
	{
		cout<<2ll*100000*100000<<endl;
		return 0;
	}
	else if(t=="10")
	{
		cout<<1ll*100000*100000<<endl;
		return 0;
	}
	else if(t=="01")
	{
		cout<<1ll*100000*100000 - 1<<endl;
		return 0;
	}
	else if(t=="11")
	{
		cout<<1ll*100000*100000<<endl;
		return 0;
	}
	else if(t=="00")
	{
		cout<<0<<endl;
		return 0;
	}

	int len = t.length();
	string f3 = t.substr(0,3);
	if(f3=="111"||f3=="000"||f3=="001"||f3=="100"||f3=="010") cout<<0<<endl;
	else
	{
		bool can=true;
		int ans = 0;
		for(int i=0;i+3<len;i+=3)
		{
			if(t.substr(i,3)==f3) continue;
			else can=false;
		}
		
		if(len%3==1)
		{
			if(t[len-1]!=f3[0]) can=false;
		}
		else if(len%3==2)
		{
			if(t[len-2]!=f3[0]||t[len-1]!=f3[1]) can=false;
		}

		if(!can) cout<<0<<endl;
		else
		{
			for(auto c:t) ans += (c=='0');
			if(t[len-1]=='0')
				cout<<1ll*100000*100000 - ans + 1<<endl;
			else cout<<1ll*100000*100000 - ans<<endl;
		}
	}
	
}	