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
	int n,k;
	cin>>n>>k;
	if(n==1)
	{
		cout<<"a"<<endl;
		return 0;
	}
	string s = "aa";
	vvi H(k);
	H[0].push_back(0);
	for(int i=1;i<min(k*k-1,n-1);i++)
	{
		if(s[i]-'a'!=k-1 || (!H[k-1].empty()))
		{
			if(H[s[i]-'a'].empty())
			{
				s += 'a';
				H[s[i]-'a'].push_back(0);
			}
			else
			{
				s += ('a' + (H[s[i]-'a'].back()+1));
				H[s[i]-'a'].push_back(H[s[i]-'a'].back()+1);
			}
		}
		else
		{
			s += 'b';
			H[k-1].push_back(1);
		}
	}
	if(s.length()==n) cout<<s<<endl;
	else
	{
		int len = s.length();
		int times = n/len;
		string ans = s;
		for(int i=1;i<times;i++) ans += s;
		ans += s.substr(0,n%len);
		cout<<ans<<endl;
	}

}	