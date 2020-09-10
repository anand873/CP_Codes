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

vl do_fun(vl A)
{
	int n=A.size();
	if(n==1) return A;
	if(n==2)
	{
		vl X = {A[0]+A[1] + (A[0]+1)%2};
		return X;
	}
	else if(n==3)
	{
		vl X;
		X = {A[0],A[1]+A[2]+(A[1]+1)%2};
		return X;
	}
	else
	{
		vl X;
		reverse(all(A));
		for(int i=0;i+3<n;i+=4)
		{
			X.push_back(A[i]+A[i+1]+A[i+2]+A[i+3] + 2 - A[i]%2);
		}
		for(int i=n-n%4;i<n;i++) X.push_back(A[i]);
		reverse(all(X));
		return do_fun(X); 
	}
}

int main()
{
	fastio
	test()
	{
		int n;
		cin>>n;
		vl A(n);
		take(A,0,n);
		vl X = do_fun(A);
		cout<<X.size()<<endl;
		prinv(X);
	}
}