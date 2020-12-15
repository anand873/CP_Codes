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
const int MOD = 998244353,MAX = 3e5+5;
const ll INF = 1e18+5;

int sq(int x)
{
	return x*x;
}

int main()
{
	fastio
	int n;
	cin>>n;
	vi A(n);
	take(A,0,n);
	int cnt1 = accumulate(all(A),0);
	vvi X(cnt1+1,vi(2));
	int x = 0;
	for(int i=0;i<n;i++)
	{
		if(A[i]==0)
		{
			X[x][0]++;
			if(x>0) X[x-1][1]++; 
		}
		if(A[i]==1)
		{
			x++;
		}
	}

	int ans = sq(n-x);
	for(int i=0;i<=x;i++) ans -= X[i][0]*X[i][0];
	ans/=2;	
	
	cout<<ans<<" ";
	int tot = n*(n-1)/2;
	for(int k=1;k<=tot;k++)
	{
		int diffr = 0;
		int diffl = 0;
		int l=-1,r=-1;
		for(int i=0;i<x;i++)
		{
			if(X[i][1]>0&&diffr>=sq(X[i][0]+1)+sq(X[i][1]-1) - sq(X[i][0])-sq(X[i][1]))
			{
				diffr = sq(X[i][0]+1)+sq(X[i][1]-1) - sq(X[i][0])-sq(X[i][1]);
				r = i;
			}
			if(X[i][0]>0&&diffl>=sq(X[i][0]-1)+sq(X[i][1]+1) - sq(X[i][0])-sq(X[i][1]))
			{
				diffl = sq(X[i][0]-1)+sq(X[i][1]+1) - sq(X[i][0])-sq(X[i][1]);
				l = i;
			}
		}
		if(diffl==diffr&&diffl==0)
		{
			for(int i=0;i<x;i++)
			{
				if(X[i][0]==X[i][1]+1) {diffl=i;break;}
				if(X[i][0]==X[i][1]-1) {diffr=i;break;}
			}
		}
		if(diffl<=diffr)
		{
			X[l][0]--;
			X[l][1]++;
			X[l+1][0]++;
			if(l>=1) X[l-1][1]--;
			ans -= diffl/2;
		}
		else
		{
			X[r][0]++;
			X[r][1]--;
			X[r+1][0]--;
			if(r>=1) X[r-1][1]++;
			ans -= diffr/2;
		}
		cout<<ans<<" ";
	}
	cout<<endl;

}	