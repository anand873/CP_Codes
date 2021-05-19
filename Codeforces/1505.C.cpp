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
	string s;
	cin>>s;
	if(s.length()==1 || s.length()==2) {cout<<"YES";return 0;}
	int last = s[1] - 'A';
	int seclast = s[0] - 'A';
	bool is = true;
	for(int i=2;i<s.length();i++)
	{
		if(s[i] - 'A' == (last+seclast)%26)
		{
			seclast = last;
			last = s[i] - 'A';
		}
		else is = false;
	}
	if(is) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}	