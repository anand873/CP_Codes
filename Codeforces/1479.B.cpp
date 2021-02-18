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
	int n;
	cin>>n;
	vi A(n+1);
	take(A,1,n);
	vector<int> B,W;
	B.push_back(0);
	W.push_back(0);

	B.push_back(A[1]);
	for(int i=2;i<=n;i++)
	{
		if(A[i]!=B.back())
		{
			if(i==n)
			{
				B.push_back(A[i]);
			}
			else
			{
				if(A[i]==A[i+1])
				{
					W.push_back(A[i]);
				}
				else
				{
					if(B.back() == A[i+1] || W.back() == A[i])
					{
						B.push_back(A[i]);
					}
					else W.push_back(A[i]);
				}
			}
		}
		else
		{
			W.push_back(A[i]);
		}
	}
	
	int ans = 0;
	for(int i=1;i<B.size();i++)
	{
		// cout<<B[i]<<" ";
		if(B[i]!=B[i-1]) ans++;
	}
	// cout<<endl;
	for(int i=1;i<W.size();i++)
	{
		// cout<<W[i]<<" ";
		if(W[i]!=W[i-1]) ans++;
	}
	// cout<<endl;
	cout<<ans<<endl;
}	