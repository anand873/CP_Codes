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
const int MOD = 998244353,MAX = 1e6+5;
const ll INF = 1e18+5;

ll powN(ll a,ll p)
{
	if(p==0) return 1;
	ll z=powN(a,p/2);
	z=(z*z)%MOD;
	if(p%2) z=(z*a)%MOD;
	return z;
}

ll C2(ll n)
{
	return (n * (n-1) / 2) % MOD; 
}

int main()
{
	int n;
	cin>>n;
	vector<ll> C(n+1);
	for(int i=1;i<=n;i++)
	{
		char c;
		cin>>c;
		if(c=='-') C[i] = -1;
		else cin>>C[i];
	}

	vl dp(n+1), ms(n+1), sms(n+1);

	dp[0] = 0;
	ms[0] = 0;
	sms[0] = 0;
	vector<ll> Numbers;
	for(int i=1;i<=n;i++)
	{
		if(C[i]!=-1)
		{
			int how = 0;
			int tot = Numbers.size();
			for(int j=0;j<tot;j++)
			{
				if(Numbers[j] <= C[i])
				{
					sms[i] = (sms[i] + ((Numbers[j] * j % MOD) * powN(2ll,tot-j-1)) % MOD ) % MOD;
					ms[i] = (ms[i] + (Numbers[j] * powN(2ll,tot-j-1) % MOD) ) % MOD;
				}
				else
				{
					how++;
					sms[i] = (sms[i] + (Numbers[j] * powN(2ll,tot-j-1) % MOD )) % MOD;
				}
			}
			ms[i] = (ms[i] + C[i] * powN(2ll,how) % MOD) % MOD;
			Numbers.push_back(C[i]);
			
			for(int j=0;j<i;j++)
			{
				dp[i] = (dp[i] + dp[j])%MOD;
			}
			dp[i] = (dp[i] + C[i] * powN(2ll,i-1) % MOD) % MOD;
		}
		else
		{
			for(int j=0;j<i;j++)
			{
				dp[i] = (dp[i] + dp[j] - ms[j])%MOD;
				if(dp[i] < 0) dp[i] += MOD;

				ms[i] = (ms[i] + sms[j]) % MOD;
			}

			int tot = Numbers.size();
			for(int j=2;j<tot;j++)
			{
				sms[i] = (sms[i] + ((Numbers[j] * C2(j) % MOD) * powN(2ll,tot-j-1)) % MOD ) % MOD;
			}
		}
	}
	prinv(dp);
	prinv(ms);
	prinv(sms);
	ll ans = 0;
	for(int i=0;i<=n;i++)
	{
		ans = (ans + dp[i])%MOD;
	}
	cout<<ans<<endl;
}	