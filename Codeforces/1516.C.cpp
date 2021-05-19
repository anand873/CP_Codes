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
	int n;
	cin>>n;
	vi A(n+1);
	take(A,1,n);
	set<int> S;
	S.insert(0);
	int sum = 0;
	for(int i=1;i<=n;i++)
	{
		sum += A[i];
		set<int> NS = S;
		for(auto s:S)
		{
			NS.insert(s+A[i]);
		}
		S = NS;
	}
	if(sum%2 || S.count(sum/2)==0)
	{
		cout<<0<<endl;
	}
	else
	{
		bool can = false;
		int idx = -1;
		for(int i=1;i<=n;i++)
		{
			if(A[i]%2) {idx = i;can = true;}
		}
		if(can)
		{
			cout<<1<<endl;
			cout<<idx<<endl;
		}
		else
		{
			cout<<1<<endl;
			int g=0;
			for(int i=1;i<=n;i++)
			{
				g = __gcd(g,A[i]);
			}
			for(int i=1;i<=n;i++) A[i]/=g;

			int idx=0;
			for(int i=1;i<=n;i++)
			{
				if(A[i]%2) idx = i;
			}
			cout<<idx<<endl;
		}

	}
}	