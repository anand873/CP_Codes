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
const int MOD = 1e9+7,MAX = 2e5+5;
const ll INF = 1e18+5;
const int p = 31;

int main()
{
	fastio
	string s;
	cin>>s;
	string t;
	cin>>t;

	ll hash_t = 0;
    ll p_pow = 1;
    for(auto c:t) 
    {
        hash_t = (hash_t + (c-'a'+1) *p_pow)%MOD;
        p_pow = (p_pow * p) % MOD;
    }
    p_pow = 1;
	int n = s.length();
	vl H(2*n+1);
	string news = s+s;
	
	vl P(2*n+1);
	P[0] = 1;
	for(int i=1;i<=2*n;i++)
	{
		P[i] = (P[i-1]*p)%MOD;
	}

	for(int i=0;i<2*n;i++)
	{
		H[i+1] = (H[i] + (news[i]-'a'+1)*P[i]%MOD)%MOD;
	}
	vi HMU(2*n+1);
	int tlen = t.length();
	ll tot = 0;
	for(int i=tlen;i<2*n;i++)
	{
		if(((H[i]-H[i-tlen])%MOD+MOD)%MOD == (hash_t*P[i-tlen])%MOD)
		{
			HMU[i] = HMU[i-1]+1;
		}
		else HMU[i] = HMU[i-1];
	}
	tot = HMU[n+tlen-1];

	int q;
	cin>>q;
	while(q--)
	{
		int N;
		cin>>N;

		int full = N/n;
		int half = N%n;

		if(full==0)
		{
			cout<<HMU[half]<<endl;
		}
		else
		{
			int ans = 0;
			ans += (full-1)*tot;
			ans += HMU[n+half];
			cout<<ans<<endl;

		}
	}

}
