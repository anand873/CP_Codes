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
            	is_prime[j] = false;
    	}
	}
}
//////////////////Sieve////////////////////

vvi V(MAX);

int main()
{	
	int n;
	cin>>n;
	V.resize(n+1);
	map<pii,int> M;
	vi ind(n+1);
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		if(u>v) swap(u,v);
		V[u].push_back(v);
		V[v].push_back(u);
		M[{u,v}]=i+1;
		ind[u]++;
		ind[v]++;
	}
	// for(auto m:M)
	// {
	// 	cout<<m.first.first<<", "<<m.first.second<<" "<<m.second<<endl;
	// }
	set<int> st;
	int how=0;
	//prin(ind);
	for(int i=1;i<=n;i++)
	{
		if(ind[i]==1)
		{
			how++;
			st.insert(i);
		}
	}
	if(how==2)
	{
		for(int i=1;i<n;i++)
		{
			cout<<i-1<<endl;
		}
	}
	else
	{
		//prin(st);
		vi Ans(n+1,-1);
		int i=0;
		for(auto s:st)
		{
			int u=s;
			int v=V[u][0];
			if(u>v) swap(u,v);
			Ans[M[{u,v}]]=i;
			i++;
			if(i==3) break;
			
		}
		for(int j=1;j<=n;j++)
		{
			if(Ans[j]==-1) {Ans[j]=i;i++;}
		}
		for(int i=1;i<n;i++)
		{
			cout<<Ans[i]<<endl;
		}
	}


}		