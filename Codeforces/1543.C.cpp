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
const int MOD = 1e9 + 7,MAX = 1e6 + 5;
const ll INF = 1e18 + 5;

ll X = 1000000000;

ll E(ll C, ll M, ll P, ll V)
{
	// cout<<C<<" "<<M<<" "<<P<<" "<<V<<endl;
	ll sum = P*X;

	if(C<=V && C!=0)
	{
		// cout<<1<<endl;
		if(M!=0)
			sum += C*(X + E(0, M + C/2, P + C/2, V));
		else
			sum += C*(X + E(0, 0, P + C, V));
	}
	else if(C!=0)
	{
		// cout<<2<<endl;
		if(M!=0)
			sum += C*(X + E(C - V, M + V/2, P + V/2, V));
		else
			sum += C*(X + E(C - V, 0, P + V, V));
	}

	if(M<=V && M!=0)
	{
		// cout<<3<<endl;
		if(C!=0)
			sum += M*(X + E(C + M/2, 0, P + M/2, V));
		else
			sum += M*(X + E(0, 0, P + M, V));
	}
	else if(M!=0)
	{
		// cout<<4<<endl;
		if(C!=0)
			sum += M*(X + E(C + V/2, M - V, P + V/2, V));
		else
			sum += M*(X + E(0, M - V, P + V, V));
	}
	// cout<<sum<<endl;
	return sum / X;
}

int main()
{
	test()
	{
		float c,m,p,v;
		cin>>c>>m>>p>>v;
		ll C,M,P,V;
		C = X*c;
		M = X*m;
		P = X*p;
		V = X*v;

		ll ans = E(C,M,P,V);
		printf("%.12f\n",ans * 1.0 / X);

	}
}	