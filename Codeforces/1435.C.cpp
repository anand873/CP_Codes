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
	vl A(6);
	take(A,0,6);
	sort(all(A));
	int n;
	cin>>n;
	vl B(n);
	take(B,0,n);
	sort(all(B));

	// cout<<abs((B[n-1]-A[5]) - (B[0]-A[0]))<<endl;
	vvl X(n,vl(6));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<6;j++)
		{
			X[i][j] = B[i] - A[j];
		}
		sort(all(X[i]));
	}
	int ans = 0;
	set<pii> Min;
	for(int i=0;i<n;i++)
	{
		Min.insert({X[i][0],i});
	}
	int range = MOD;
	vi In(n);
	while(1)
	{
		range = min(range,(Min.rbegin()->first-Min.begin()->first));
		int low = Min.begin()->first;
		int idx = Min.begin()->second;
		Min.erase(Min.begin());
		if(In[idx]==5) break;
		Min.insert({X[idx][++In[idx]],idx});
	}
	cout<<range<<endl;
}	