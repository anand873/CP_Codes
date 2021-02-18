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
	test()
	{
		int n,m;
		cin>>n>>m;
		vi A(n+1),B(n+1),C(m+1);
		take(A,1,n);
		take(B,1,n);
		take(C,1,m);
		set<int> Avail;
		map<int,vi> Not_Done,Done;
		for(int i=1;i<=n;i++)
		{
			if(A[i]!=B[i]) Not_Done[B[i]].push_back(i);
			else Done[B[i]].push_back(i);
		}
		bool can = true;
		vi Ans(m+1);
		for(int i=m;i>=1;i--)
		{
			if(Not_Done[C[i]].size()>0)
			{
				Ans[i] = Not_Done[C[i]].back();
				A[Ans[i]] = C[i];
				Not_Done[C[i]].pop_back();
				Avail.insert(Ans[i]);
			}
			else if(Avail.size()>0)
			{
				Ans[i] = *Avail.begin();
			}
			else if(Done[C[i]].size()>0)
			{
				Ans[i] = Done[C[i]][0];
				Avail.insert(Ans[i]);
			}
			else {can = false;break;}
		}
		for(int i=1;i<=n;i++)
		{
			if(A[i]!=B[i]) can = false;
		}
		if(can)
		{
			cout<<"Yes"<<endl;
			for(int i=1;i<=m;i++)
			{
				cout<<Ans[i]<<" ";
			}
			cout<<"\n";
		}
		else cout<<"No\n";
	}
}	