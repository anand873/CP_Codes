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
#define test(t) int t;cin>>t;while(t--)
#define forn(i,f,n) for(int i=f;i<f+n;i++)
#define rforn(i,l,n) for(int i=l;i>l-n;i--)
#define all(v) v.begin(),v.end()
#define prin(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int i=f;i<f+n;i++) cin>>V[i]
#define what(x) cerr<<#x<<" = "<<x<<endl
#define KStest(t,t1) int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "

const int MOD = 1e9+7,MAX = 1e6+5;
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

vector<int> parent(MAX,-1);
vector<int> size(MAX,0);
void make_set(int i)
{
	parent[i]=i;
	size[i]=1;
}

int find_set(int i)
{
	if(parent[i]==i) return i;
	else return parent[i]=find_set(parent[i]);
}

void union_set(int i,int j)
{
	i=find_set(i);
	j=find_set(j);
	if(i!=j)
	{
		if(size[i]>size[j]) swap(i,j);
		parent[i]=j;
		size[j]+=size[i];
	}
}


int main()
{	
	int n,m;
	cin>>n>>m;
	vector<string> X(n);
	take(X,0,n);
	set<int> sp;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(X[i][j]=='#')
			{
				if(i!=0&&X[i-1][j]=='.') sp.insert((i-1)*m+j);
				if(j!=0&&X[i][j-1]=='.') sp.insert(i*m+j-1);
				if(i!=n-1&&X[i+1][j]=='.') sp.insert((i+1)*m+j);
				if(j!=m-1&&X[i][j+1]=='.') sp.insert(i*m+j+1);
				if(i!=0&&j!=0&&X[i-1][j-1]=='.') sp.insert((i-1)*m+j-1);
				if(i!=0&&j!=m-1&&X[i-1][j+1]=='.') sp.insert((i-1)*m+j+1);
				if(i!=n-1&&j!=0&&X[i+1][j-1]=='.') sp.insert((i+1)*m+j-1);
				if(i!=n-1&&j!=m-1&&X[i+1][j+1]=='.') sp.insert((i+1)*m+j+1);
			}
		}
	}
	for(auto x:sp) make_set(x);
	for(auto x:sp)
	{
		if((x+1)%m!=0&&sp.count(x+1)) union_set(x,x+1);
		if((x-1+m)%m!=m-1&&sp.count(x-1)) union_set(x,x-1);
		if(sp.count(x+m)) union_set(x,x+m);
		if(sp.count(x-m)) union_set(x,x-m);
		if(sp.count(x+m-1)&&(x-1+m)%m!=m-1) union_set(x,x+m-1);
		if(sp.count(x+m+1)&&(x+1)%m!=0) union_set(x,x+m+1);
		if(sp.count(x-m-1)&&(x-1+m)%m!=m-1) union_set(x,x-m-1);
		if(sp.count(x-m+1)&&(x+1)%m!=0) union_set(x,x-m+1);
	}
	int ans=0;
	for(auto x:sp) ans=max(ans,size[find_set(x)]);
	cout<<ans<<endl;
}		