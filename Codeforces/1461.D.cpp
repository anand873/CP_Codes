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

set<pii> GI;
vi A;

void fun (int l,int r)
{
	if(l>r) return;

	if(GI.count({l,r})) return;
	else GI.insert({l,r});
	if(l==r) return;
	int m = (A[l] + A[r])/2;
	int idx = -1;
	int low=l,high=r;
	while(low<=high)
	{
		// cout<<low<<" "<<high<<endl;
		int mid = (low+high)/2;
		if(A[mid]<=m) {idx=mid;low=mid+1;}
		else high = mid-1;
	}
	fun(l,idx);
	fun(idx+1,r);
}

void testcase()
{
	int n,q;
	cin>>n>>q;
	A.resize(n+1);
	take(A,1,n);
	sort(1+all(A));
	fun(1,n);
	// cout<<GI.size()<<endl;
	vl P(n+1);
	for(int i=1;i<=n;i++) P[i] = P[i-1] + A[i];
	set<ll> CAN;
	for(auto p:GI)
	{
		CAN.insert(P[p.second]-P[p.first-1]);
	}

	for(int i=0;i<q;i++)
	{
		int s;
		cin>>s;
		if(CAN.count(s)) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	GI.clear();
	A.clear();
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		testcase();
	}
}	