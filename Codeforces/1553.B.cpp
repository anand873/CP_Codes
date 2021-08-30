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
const int MOD = 1e9,MAX = 5e5+5;
const ll INF = 1e18+5;

int main()
{
	test()
	{
		string s1,s2;
		cin>>s1>>s2;
		int n = s1.size();
		int m = s2.size();
		vector<set<string>> Vf(n),Vb(n);
		for(int i=0;i<n;i++)
		{
			string ss = "";
			Vf[i].insert(ss);
			Vb[i].insert(ss);
			for(int j=i;j<n;j++)
			{
				ss.push_back(s1[j]);
				Vf[i].insert(ss);
			}
			ss = "";
			for(int j=i;j>=0;j--)
			{
				ss.push_back(s1[j]);
				Vb[i].insert(ss);
			}
		}
		bool can = false;
		for(int i=1;i<=m;i++)
		{
			string tt = s2.substr(0,i);
			string rem = s2.substr(i);
			// cout<<tt<<" "<<rem<<endl;
			for(int st=0;st<n;st++)
			{
				if(Vf[st].count(tt))
				{
					int en = st + i - 2;
					if(en == -1)
					{
						if(rem == "") can = true;
					}
					else
					{
						if(Vb[en].count(rem)) can = true;
					}
				}
			}
		}
		if(can) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}	