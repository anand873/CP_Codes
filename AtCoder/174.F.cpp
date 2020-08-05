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

int block;
bool cmp(pair<pii,int> a,pair<pii,int> b)
{
	if((a.first.first-1)/block==(b.first.first-1)/block)
	{
		return a.first.second<b.first.second;
	}
	else return (a.first.first-1)/block<(b.first.first-1)/block;
}

int main()
{
	fastio
	int n,q;
	cin>>n>>q;
	vl A(n+1);
	block=sqrt(n);
	take(A,1,n);
	vector<pair<pii,int>> Q(q);
	
	for(int i=0;i<q;i++)
	{
		int l,r;
		cin>>l>>r;
		Q[i].first.first=l;
		Q[i].first.second=r;
		Q[i].second=i;
	}
	sort(all(Q),cmp);
	
	int start=0;
	int end=0;
	vi F(n+1);
	vi Ans(q);
	int ans=0;
	for(auto query:Q)
	{
		while(start>query.first.first)
		{
			start--;
			F[A[start]]++;
			if(F[A[start]]==1) ans++;
		}
		while(end<query.first.second)
		{
			end++;
			F[A[end]]++;
			if(F[A[end]]==1) ans++;
		}
		while(start<query.first.first)
		{
			if(start!=0) F[A[start]]--;
			if(F[A[start]]==0) ans--;
			start++;
		}
		while(end>query.first.second)
		{
			F[A[end]]--;
			if(F[A[end]]==0) ans--;
			end--;
		}
		Ans[query.second]=ans+1;
	}
	for(int i=0;i<q;i++)
	{
		cout<<Ans[i]<<endl;
	}
	
}