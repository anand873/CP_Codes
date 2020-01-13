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

#define test(t) int t;cin>>t;while(t--)
#define forn(i,n) for(i=0;i<n;i++)
#define rforn(i,n) for(i=n-1;i>=0;i--)
#define all(v) (v).begin(),(v).end()
const int MOD = 1e9+7,MAX = 1e5+5;
ll powN(ll a,ll p)
{
	if(p==0) return 1;
	ll z=powN(a,p/2);
	z=(z*z)%MOD;
	if(p%2) z=(z*a)%MOD;
	return z;
}
vector<bool> is_prime(MAX+1, true);
void Sieve()
{
	is_prime[0] = is_prime[1] = false;
	int i,j;
	for (i = 2; i*i <= MAX; i++) 
	{
    	if (is_prime[i]) 
    	{
        	for (j = i * i; j <= MAX; j += i)
            	is_prime[j] = false;
    	}
	}
}
ll modInv(ll a)
{
	return powN(a,MOD-2);
}



int main()
{
	test(t)
	{
		int n,q;
		cin>>n>>q;
		string s;
		cin>>s;
		double pi = 3.14159265;
		vector<pair<pair<double,double>,double>> V;
		V.push_back({{0,0},0});
		for(int i=0;i<n;i++)
		{
			double x,y;
			int d;
			d=(s[i]-'0');

			double deg=d*pi/3;
			//cout<<d<<" "<<V[i].first.first<<endl;
			x=V[i].first.first+cos(deg);
			y=V[i].first.second+sin(deg);
			//cout<<x<<" "<<y<<endl;
			V.push_back({{x,y},deg});
		}
		for(int i=0;i<n+1;i++) cout<<V[i].first.first<<" "<<V[i].first.second<<" "<<V[i].second<<endl;
		while(q--)
		{
			int l,r;
			cin>>l>>r;
			double xn,yn;
			xn=(V[r].first.first-V[l-1].first.first);
			yn=V[r].first.second-V[l-1].first.second;;
			printf("%.7lf %.7lf\n",xn,yn);
		}
	}
}