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
const int MOD = 1e9+7,MAX = 1e5+5;
const ll INF = 1e18+5;

int main()
{
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;

	set<string> S;
	string curr;
	string tot;

	tot.push_back(s[0]);
	tot.push_back(s[0]);
	int minx = 0;

	curr.push_back(s[0]);
	for(int i=0;i<n;i++)
	{
		curr.pop_back();
		curr += s[i];
		curr.push_back(s[0]);

		if(curr <= tot)
		{
			minx = i;
			tot = curr;
		}
	}

	tot.pop_back();
	while(2* tot.length() <= k)
	{
		tot += tot;
	}
	for(int i=0;i<tot.length();i++)
	{
		if(tot.length()!=k)
		{
			tot += tot[i];
		}
		else break;
	}
	cout<<tot<<endl;

}	