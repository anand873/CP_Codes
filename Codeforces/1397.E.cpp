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
	ll n,r1,r2,r3,d;
	cin>>n>>r1>>r2>>r3>>d;

	r1 = min(r1,r3);

	vi A(n);
	take(A,0,n);
	ll t = 0;
	int notdone=n+1;
	vector<bool> D(n);
	for(int i=0;i<n-1;i++)
	{
		int x;
		if(notdone<i) x = min(r1,r2);
		else x = min(r1,r2)+d;
		
		if(r1*A[i]+r3<=r2+x)
		{
			D[i]=true;
			t += r1*A[i]+r3+d;
		}
		else
		{
			t += r2+d;
		}
		cout<<t<<endl;
	}
	t += min(r1*A[n-1]+r3, r2+d+d+min(r1,r2));

	if(notdone<=n-2) t+=d;

	for(int i=n-2;i>=notdone;i--)
	{
		if(!D[i])
		{
			t += min(r1,r2);
		}
		t+=d;
	}
	t-=d;
	cout<<t<<endl;

	


}	