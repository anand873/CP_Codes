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
	int q;
	cin>>q;
	vi A(q+1);
	vi C(q+1);
	cin>>A[0]>>C[0];
	vvi P(q+1,vi(20,-1));

	for(int i=1;i<=q;i++)
	{
		int type;
		cin>>type;
		if(type==1)
		{
			cin>>P[i][0]>>A[i]>>C[i];
			for(int j=1;j<20;j++)
			{
				if(P[i][j-1]==-1) break;
				P[i][j] = P[P[i][j-1]][j-1];
			}
		}
		else
		{
			int v,w;
			cin>>v>>w;
			// cerr<<v<<": ";
			ll ans1 = 0, ans2 = 0;

			while(w)
			{
				int curr = v;
				for(int j=19;j>=0;j--)
				{
					if(P[curr][j]!=-1 && A[P[curr][j]]>0)
					{
						curr = P[curr][j];
					}
				}
				// cerr<<curr<<" ";
				ll cantake = min(w,A[curr]);
				if(cantake==0) break;
				else
				{
					ans2 += cantake;
					ans1 += cantake*C[curr];
					w -= cantake;
					A[curr] -= cantake;
				}
			}

			// cerr<<endl;
			cout<<ans2<<" "<<ans1<<endl;
		}
	}

}	