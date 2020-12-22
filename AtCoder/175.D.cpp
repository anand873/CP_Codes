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
	ll n,k;
	cin>>n>>k;
	vl P(n+1);
	take(P,1,n);
	vl C(n+1);
	take(C,1,n);
	ll ans = -INF;
	for(int st=1;st<=n;st++)
	{
		ll curr = P[st];
		ll temp = 0;
		ll upto = C[curr];
		ll mov = 1;
		temp = upto;
		map<ll,ll> M;
		M[0] = 0;
		M[1] = temp;

		while(curr!=st)
		{
			if(mov==k) break;
			upto += C[P[curr]];
			temp = max(temp,upto);
			curr = P[curr];
			mov++;
			M[mov] = temp;
		}
		// cout<<st<<" "<<temp<<endl;
		if(mov==k)
		{
			ans = max(ans,temp);
		}
		else
		{
			if(k%mov!=0) ans = max({ans, upto*(k/mov) + max(0ll,M[k%mov]),temp});
			else
			{
				ans = max({ans,upto*(k/mov-1)+max(0ll,temp),temp});
			}
		}
	}
	cout<<ans<<endl;
}	