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
		int n,x;
		cin>>n>>x;
		vi A(n+1);
		take(A,1,n);
		A[0] = -MOD;
		int x_gre = n+1;
		if(A[1]>x) x_gre = 1;

		int ans = 0;
		for(int i=2;i<=n;i++)
		{
			if(A[i]<A[i-1])
			{
				if(x_gre==n+1) {ans = -1;break;}
				else
				{
					for(int j=x_gre;j<=i-1;j++)
					{
						int temp = A[j];
						A[j] = x;
						if(temp!=x) ans++;
						x = temp;
					}
					x_gre = n+1;
					if(A[i]<A[i-1])
					{
						ans = -1;
						break;
					}
				}
			}
			else
			{
				if(A[i]>x) x_gre = min(x_gre,i);
			}
		}
		cout<<ans<<endl;
	}
}	