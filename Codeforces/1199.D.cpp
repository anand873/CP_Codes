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
#define forn(i,f,n) for(int i=f;i<f+n;i++)
#define rforn(i,l,n) for(int i=l;i>l-n;i--)
#define all(v) v.begin(),v.end()
#define prin(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int i=f;i<f+n;i++) cin>>V[i]
#define what(x) cerr<<#x<<" = "<<x<<endl
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "

const int MOD = 1e9+7,MAX = 1e5+5;
/////////////////FastExp///////////////////
ll powN(ll a,ll p)
{
	if(p==0) return 1;
	ll z=powN(a,p/2);
	z=(z*z)%MOD;
	if(p%2) z=(z*a)%MOD;
	return z;
}
/////////////////FastExp///////////////////
//////////////////Sieve////////////////////
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
            {
				is_prime[j] = false;
    		}
    	}
	}
}
//////////////////Sieve////////////////////

int main()
{
	int n;
	cin>>n;
	vl A(n);
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	int q;
	cin>>q;
	int qq=q;
	vector<pll> Q;
	while(q--)
	{
		int c;
		cin>>c;
		if(c==2)
		{
			ll x;
			cin>>x;
			Q.push_back({-1,x});
		}
		else
		{
			ll p,x;
			cin>>p>>x;
			Q.push_back({p,x});
		}
	}
	//cout<<"All Query Taken"<<endl;

	int maxi=-1;
	ll maxup=0;
	for(int i=0;i<n;i++)
	{
		if(Q[i].first==-1)
		{
			if(maxup<=Q[i].second)
			{
				maxup=Q[i].second;
				maxi=i;
			}
		}
	}
	//cout<<"Max Found"<<endl;
	//what(maxup);
	for(int i=0;i<maxi;i++)
	{
		if(Q[i].first!=-1) A[Q[i].first-1]=Q[i].second;
	}
	for(int i=0;i<n;i++)
	{
		A[i]=max(A[i],maxup);
	}
	//prin(A);
	//cout<<maxi<<endl;
	//cout<<"Upto Max Done"<<endl;
	set<int> LU;
	//cout<<q<<" "<<maxi+1<<endl;
	for(int i=maxi+1;i<qq;i++)
	{
		//cout<<Q[i].first<<" "<<Q[i].second<<endl;
		if(Q[i].first!=-1)
		{
			A[Q[i].first-1]=Q[i].second;
			if(Q[i].second<maxup) LU.insert(Q[i].first-1);
		}
		else
		{
			for(auto in:LU) A[in]=max(A[in],Q[i].second);
			LU.clear();
			maxup=Q[i].second;
		}
	}
	for(int i=0;i<n;i++) cout<<A[i]<<" ";
	cout<<endl;
}		