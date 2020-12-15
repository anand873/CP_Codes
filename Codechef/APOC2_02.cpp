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
const int MOD = 1e9+7,MAX = 2e5+5;
const ll INF = 1e18+5;

int main()
{
	test()
	{
		int n,k;
		cin>>n>>k;
		vi A(n+1);
		take(A,1,n);
		int totdis = 0;
		
		set<int> M;
		for(int i=1;i<=n;i++) M.insert(A[i]);
		totdis = M.size();
		
		map<int,int> S;
		vl PS(n+1);
		for(int i=1;i<=n;i++) PS[i] = PS[i-1]+A[i];
		
		ll ans = 0; 
		for(int i=1;i<=k-1;i++) S[A[i]]++;
		for(int i=k;i<=n;i++)
		{
			S[A[i]]++;
			if(S.size()==totdis)
			{
				ans = max(ans,PS[i] - PS[i-k]);
			}
			S[A[i-k+1]]--;
			if(S[A[i-k+1]]==0) S.erase(A[i-k+1]);
		}
		cout<<ans<<endl;
	}	
}	