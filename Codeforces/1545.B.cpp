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
const int MOD = 998244353,MAX = 5e5+5;
const ll INF = 1e18+5;

ll powN(ll a,ll p)
{
	if(p==0) return 1;
	ll z=powN(a,p/2);
	z=(z*z)%MOD;
	if(p%2) z=(z*a)%MOD;
	return z;
}

struct PnC
{
	int n;
	vl F,I;
	void init(int n)
	{
		F.resize(n+1);
		I.resize(n+1);
		F[0]=I[0]=1;
		for(int i=1;i<=n;i++)
		{
			F[i]=(F[i-1]*i)%MOD;
			I[i]=powN(F[i],MOD-2);
		}
	}
	ll nCr(int n,int r)
	{
		if(r>n) return 0;
		return (((F[n]*I[r])%MOD)*I[n-r])%MOD;
	}
};

int main()
{
	PnC P;
	P.init(MAX);
	test()
	{
		int n;
		cin>>n;
		string s;
		cin>>s;
		if(n<=2)
		{
			cout<<1<<endl;
			continue;
		}
		int zer = 0;
		for(auto c:s)
		{
			if(c=='0') zer++;
		}
		
		int st = 0;
		while(st<n && s[st]=='1') st++;

		if(st==n)
		{
			cout<<1<<endl;
		}
		else
		{
			int en = 0;
			while(en<n && s[n-1-en]=='1') en++;

			if(st%2) st = 1;
			else st = 0;
			if(en%2) en = n-1;
			else en = n;
			int curr = 0;
			int ans = 0;
			for(int i=st;i<en;i++)
			{
				if(s[i]=='1')
				{
					curr++;
				}
				else
				{
					ans += curr/2;
					curr=0;
				}
			}
			ans += curr/2;
			cout<<P.nCr(zer + ans,ans)<<endl;
		}

	}
}	