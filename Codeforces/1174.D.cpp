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
	ll x;
	cin>>n>>x;
	if(x>=(1ll<<n))
	{
		vl B;
		int tot = 1ll<<n;
		cout<<tot-1<<endl;
		for(int i=1;i<tot;i++)
		{
			B.push_back(i);
		}
		vl A(tot-1);
		if(tot==1) return 0;
		A[0] = B[0];
		for(int i=1;i<tot-1;i++)
		{
			A[i] = B[i-1]^B[i];
		}
		prinv(A);
	}
	else
	{
		vl B;
		set<ll> S;
		int tot = 1ll<<n;
		for(int i=1;i<tot;i++)
		{
			if(S.count(x^i)==0&&i!=x)
			{
				S.insert(i);
			}
		}
		for(auto s:S) B.push_back(s);
		tot = B.size();
		cout<<tot<<endl;
		if(tot==0) return 0;
		vl A(tot);
		A[0] = B[0];
		for(int i=1;i<tot;i++)
		{
			A[i] = B[i-1]^B[i];
		}
		prinv(A);
	}
}	