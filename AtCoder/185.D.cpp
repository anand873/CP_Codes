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

int val(int mid, vi &A)
{
	int ans = 0;
	int sz = A.size();
	for(int i=1;i<sz;i++)
	{
		ans += ((A[i]-A[i-1]-1)+(mid-1))/mid;
	}
	return ans;
}

int main()
{
	int n,m;
	cin>>n>>m;
	vector<int> A;
	int gcd = 0;
	for(int i=1;i<=m;i++)
	{
		int x;
		cin>>x;
		A.push_back(x);
	}
	A.push_back(0);
	A.push_back(n+1);
	sort(all(A));
	int mingap=n+1;
	for(int i=1;i<=m+1;i++)
	{
		if(A[i]-A[i-1]-1==0) continue;
		mingap = min(mingap,A[i]-A[i-1]-1);
	}
	if(n==m) {cout<<0<<endl;return 0;}
	int ans = val(mingap,A);
	cout<<ans<<endl;


}	