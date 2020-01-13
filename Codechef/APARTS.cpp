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

int n,m;
set<pair<int,int>> C,D;
void f(int i,int j)
{
	if(C.count({i,j})==1||D.count({i,j})==1) return;
	if(i>=1&&j>=1) {D.insert({i,j});f(i-1,j-1);}
	if(i>=1&&j>=1) {D.insert({i,j});f(i-1,j);}
	if(i>=1&&j<=m) {D.insert({i,j});f(i-1,j+1);}
	return;
}

int main()
{
	test(t)
	{
		cin>>n>>m;
		vector<pair<int,int>> X(n*m+1);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				int x;
				cin>>x;
				X[x]={n-i,j+1};
			}
		}
		for(int i=X.size()-1;i>0;i--)
		{
			if(D.count({X[i].first,X[i].second})==0) C.insert({X[i].first,X[i].second});
			else continue;
			f(X[i].first-1,X[i].second);
			f(X[i].first-1,X[i].second-1);
			f(X[i].first-1,X[i].second+1);
			// cout<<endl;
			// cout<<"C: ";
			// for(auto c:C) cout<<c.first<<","<<c.second<<" ";
			// cout<<endl;
			// cout<<"D: ";
			// for(auto d:D) cout<<d.first<<","<<d.second<<" ";
			// cout<<endl;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(C.count({n+1-i,j})==1) cout<<1;
				else cout<<0;
			}
			cout<<endl;
		}
		C.clear();
		D.clear();
	}
}