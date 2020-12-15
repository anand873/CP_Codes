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
const int MOD = 1e9+7,MAX = 1e5+5;
const ll INF = 1e18+5;

int main()
{
	int n;
	cin>>n;
	vi A(n+2);
	take(A,1,n);
	if(n>=90) {cout<<1<<endl;return 0;}
	vi X(n+1);
	for(int i=1;i<=n;i++)
	{
		X[i] = A[i]^X[i-1];
	}
	A[n+1] = 2*MOD;
	int ans = MOD;
	for(int l=1;l<n;l++)
	{
		for(int r=l+1;r<=n;r++)
		{
			for(int m=l;m<r;m++)
			{
				if((X[m]^X[l-1])>(X[r]^X[m])) ans = min(ans,r-l-1);
			}
		}
	}
	if(ans==MOD) cout<<-1<<endl;
	else cout<<ans<<endl;


}	