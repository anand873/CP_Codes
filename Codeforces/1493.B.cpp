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

string rev_valid(string s, int h, int m)
{
	// cout<<s<<endl;
	reverse(all(s));
	string ns;
	for(auto c:s)
	{
		if(c=='0') ns += '0';
		if(c=='1') ns += '1';
		if(c=='2') ns += '5';
		if(c=='3' || c=='4' || c=='6' || c=='7' || c=='9') return "BAD";
		if(c=='5') ns += '2';
		if(c=='8') ns += '8';
		if(c==':') ns += ':';
	}
	if(stoi(ns.substr(0,2))<h && stoi(ns.substr(3,2))<m) return ns;
	else return "BAD";
}

int main()
{
	test()
	{
		int h,m;
		cin>>h>>m;
		string T;
		cin>>T;
		string h_h = T.substr(0,2);
		string m_m = T.substr(3,2);
		string ans;
		// cout<<h_h<<" "<<m_m<<endl;
		int hh = stoi(h_h);
		int mm = stoi(m_m);
		for(int i=0;i<3 * h * m ; i++)
		{
			string currt;
			if(hh<10)
			{
				currt += '0';
				currt += '0' + hh;
			}
			else currt += to_string(hh);
			currt += ':';
			if(mm<10)
			{
				currt += '0';
				currt += '0' + mm;
			}
			else currt += to_string(mm);



			string currrev = rev_valid(currt,h,m);
			if(currrev!="BAD")
			{
				ans = currt;
				break;
			}
			mm++;
			if(mm==m)
			{
				mm=0;
				hh++;
			}
			if(hh==h) hh=0;
		}
		cout<<ans<<endl;
	}
}	