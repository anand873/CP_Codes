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
		int n;
		cin>>n;
		vi A(n);
		take(A,0,n);
		int maxi = A[0];
		set<int> S;
		for(int i=1;i<n;i++)
		{
			maxi = max(maxi, A[i]);
			S.insert(A[i] - A[i-1]);
		}
		if(S.size()>2) cout<<-1<<endl;
		else if(S.size()==2)
		{
			if(*S.begin() >= 0 || *S.rbegin() <= 0) cout<<-1<<endl;
			else
			{
				int x = *S.begin();
				int y = *S.rbegin();
				if(y-x <= maxi) cout<<-1<<endl;
				else cout<<y-x<<" "<<y<<endl;
			}
		}
		else cout<<0<<endl;

	}
}	