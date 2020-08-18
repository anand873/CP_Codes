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
///////////////SegmentTree/////////////////
struct SegTree 
{
	int n;
	vector<ll> Tree;
	void init(int sz)
	{
		n = sz;
		Tree.resize(4*n);
	}
	void add(int k, ll x) 
	{
		k+=n;
		Tree[k]=x;
		for(k=k/2;k>=1;k/=2)
		{
			Tree[k]=Tree[2*k]+Tree[2*k+1];
		}
	}
	ll sum(int a, int b)
	{
		a+=n;b+=n;
		ll s=0;
		while(a<=b)
		{
			if(a%2==1) s+=Tree[a++];
			if(b%2==0) s+=Tree[b--];
			a/=2;b/=2;
		}
		return s;
	}
};
///////////////SegmentTree/////////////////
///////////////////PnC/////////////////////
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
///////////////////PnC/////////////////////
//////////////////Sieve////////////////////
vector<bool> is_prime(MAX, true);
vi MinDiv(MAX);
void Sieve()
{
	is_prime[0] = is_prime[1] = false;
	int i,j;
	for (i = 2; i*i <= MAX; i++) 
	{
    	if (is_prime[i]) 
    	{
    		MinDiv[i]=i;
        	for (j = i * i; j <= MAX; j += i)
            {
				is_prime[j] = false;
				MinDiv[j]=i;
    		}
    	}
	}
	for(int i=2;i<=MAX;i++) if(is_prime[i]) MinDiv[i]=i;
}
//////////////////Sieve////////////////////

vector<int> parent(20,-1);
vector<int> size(20,0);
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
	test()
	{
		int n;
		cin>>n;
		string A,B;
		cin>>A>>B;
		
		vvi V(20);
		bool can=true;
		for(int i=0;i<n;i++)
		{
			if(A[i]!=B[i])
			{
				if(A[i]<B[i])
				{
					if(parent[A[i]-'a']==-1)
					{
						make_set(A[i]-'a');
					}
					if(parent[B[i]-'a']==-1)
					{
						make_set(B[i]-'a');
					}
					union_set(A[i]-'a',B[i]-'a');
				}
				else can=false;
			}
		}
		if(!can) cout<<-1<<endl;
		else
		{
			set<int> D;
			int ans=0;
			for(int i=0;i<20;i++)
			{
				if(parent[i]!=-1)
				{
					if(D.count(find_set(i))==0)
					{
						D.insert(find_set(i));
						ans+=size[find_set(i)]-1;
					}
				}
			}
			cout<<ans<<endl;
		}
		for(int i=0;i<20;i++) parent[i]=-1;
		size.clear();

	}
}	