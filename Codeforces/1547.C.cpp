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

int main()
{
	test()
	{
		int k,n,m;
		cin>>k>>n>>m;

		vi A(n),B(m);
		take(A,0,n);
		take(B,0,m);
		A.push_back(MOD);
		B.push_back(MOD);
		// prinv(A);
		// prinv(B);
		int a = 0, b = 0;
		vi Ans(n+m);
		bool can = true;
		int newlines = 0;
		for(int i=0;i<n+m;i++)
		{
			// cout<<A[a]<<" "<<B[b]<<endl;
			if(min(A[a],B[b]) > k+newlines) {can = false;break;}
			if(A[a] < B[b])
			{
				if(A[a]==0) newlines++;
				Ans[i] = A[a];
				a++;
			}
			else
			{
				if(B[b]==0) newlines++;
				Ans[i] = B[b];
				b++;
			}
		}
		if(!can) cout<<-1<<endl;
		else
		{
			prinv(Ans);
		}

	}
}	