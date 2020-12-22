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
	inr h,w;
	cin>>h>>w;
	vpii A(h+1),B(h+1);
	int LE,RE;
	pair<pii,int> INC;
	for(int i=1;i<=h;i++)
	{
		cin>>A[i]>>B[i];
	}

	if(A[1]!=1)
	{
		LE = 1;
	}
	else LE = MOD;

	if(B[1]!=w)
	{
		RE = 1;
	}
	else RE = MOD;

	INC = {{A[i],B[i]},2};
	if(A[i]!=1||B[i]!=w) cout<<1<<endl;
	else cout<<-1<<endl;

	for(int i=2;i<=h;i++)
	{
		if(A[i]==1)
		{
			LE=-1;
			INC.first.first = max(INC.first.first,[i])
		}
		INC.first.first = min(INC.first.first,A[i]);
		INC.first.second = max(INC.first.second,B[i]);
		if(LE!=MOD||RE!=MOD)
		{
			cout<<min(LE,RE)<<endl;
			if(LE!=MOD) LE++;
			if(RE!=MOD) RE++;
		}
		else
		{
			cout<<INC.second
		}
	}
	

}	