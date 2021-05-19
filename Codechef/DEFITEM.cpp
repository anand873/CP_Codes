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
const int MOD = 1e9 + 7,MAX = 1e6 + 5;
const ll INF = 1e18+5;

int main()
{
	fastio
	test()
	{
		int n,q;
		cin>>n>>q;
		vi A(n+1);
		take(A,1,n);
		vl PS(n+1);
		unordered_map<int,int> I;
		for(int i=1;i<=n;i++)
		{
			I[A[i]] = i;
			PS[i] = PS[i-1] + A[i];
		}
		for(int i=0;i<q;i++)
		{
			int x;
			cin>>x;
			x = I[x];
			cout<<min(PS[x],PS[n]-PS[x-1])<<"\n";
		}

	}
}	