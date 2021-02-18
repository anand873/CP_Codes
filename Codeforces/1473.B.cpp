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
		string s1,s2;
		cin>>s1>>s2;
		set<char> S1,S2;
		for(auto c:s1) S1.insert(c);
		for(auto c:s2) S2.insert(c);
		if(S1.size()==1&&S2.size()==1&&s1[0]==s2[0])
		{
			int lcm = s1.length()*s2.length()/__gcd(s1.length(),s2.length());
			for(int i=0;i<lcm;i++) cout<<s1[0];
			cout<<"\n";
		}
		else
		{
			bool can=true;
			if(s1.length()>s2.length()) swap(s1,s2);
			int times = s1.length()/__gcd(s1.length(),s2.length());
			string ss2 = "";
			for(int i=0;i<times;i++) ss2 += s2;

			s2 = ss2;
			for(int i=0;i<s2.length();i++)
			{
				if(s2[i]!=s1[i%s1.length()]) can=false;
			}
			if(can) cout<<s2<<"\n";
			else cout<<-1<<endl;
		}
	}
}	