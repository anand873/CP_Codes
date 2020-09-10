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
vi A;
ll f(int l,int r)
{
	if(l==r) return (A[l]!=0);
	ll ans = 0;
	int mina=MOD;
	for(int i=l;i<=r;i++)
	{
		mina = min(mina,A[i]);
	}
	for(int i=l;i<=r;i++) A[i]-=mina;
	ans += mina;
	int curl=l;
	while(curl<=r&&A[curl]==0) curl++;

	int curr=curl;
	for(int i=curl+1;i<=r;i++)
	{
		if(A[i]>0) curr++;
		else
		{
			ans += f(curl,curr);
			curl = curr+1;
			while(curl<=r&&A[curl]==0)
			{
				curl++;
			}
			curr=curl;
			i=curr;
		}
	}
	ans += f(curl,curr);

	return min((ll)r-l+1,ans);	


}
int main()
{
	int n;
	cin>>n;
	A.resize(n+1);
	take(A,1,n);

	ll ans = 0;
	int curl=1;
	while(curl<=n&&A[curl]==0) curl++;

	int curr=curl;
	for(int i=curl+1;i<=n;i++)
	{
		if(A[i]>0) curr++;
		else
		{
			ans += f(curl,curr);
			curl = curr+1;
			while(curl<=n&&A[curl]==0)
			{
				curl++;
			}
			curr=curl;
			i=curr;
		}
	}
	ans += f(curl,curr);
	cout<<ans<<endl;
}	