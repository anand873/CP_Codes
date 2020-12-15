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

int inv(vi A)
{
	int ans=0;
	for(int i=0;i<A.size();i++)
	{
		for(int j=i+1;j<A.size();j++)
		{
			if(A[i]>A[j]) ans++;
		}
	}
	return ans;
}

int main()
{
	test()
	{
		int n=6;
		// cin>>n;
		vi P(n);
		// take(P,0,n);
		for(int i=0;i<n;i++) P[i]=i+1;
		shuffle(all(P),rng);
		cout<<endl;
		prinv(P);

		bool can=false;
		for(int i=0;i<(1<<n);i++)
		{
			vi A,B;
			for(int j=0;j<n;j++)
			{
				if((i>>j)&1) A.push_back(P[j]);
				else B.push_back(P[j]);
			}
			// prinv(A);
			// prinv(B);
			if(inv(A)==inv(B)) {prinv(A);prinv(B);can=true;}
		}
		// if(can) cout<<"YES"<<endl;
		// else cout<<"NO"<<endl;
	}
}	