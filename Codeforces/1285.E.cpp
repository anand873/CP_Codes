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

ll INF=1e9+5;
vector<int> parent(100005,-1);
vector<int> size(100005,0);
vector<ll> ma(100005,-INF);
vector<ll> mi(100005,INF);
vector<bool> DON(100005);
int n;
vpll V(100005);
void make_set(int i)
{
	parent[i]=i;
	size[i]=1;
	mi[i]=V[i].first;
	ma[i]=V[i].second;
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
		mi[j]=min(mi[i],mi[j]);
		ma[j]=max(ma[i],ma[j]);
	}
}

bool F(int x)
{
	ll rmin=INF;
	ll lmax=-INF;
	//cout<<rmin<<" "<<lmax<<endl;
	for(int i=1;i<=n;i++)
	{
		if(find_set(i)!=x) continue;
		else
		{
			//cout<<i<<" "<<V[i].first<<" "<<V[i].second<<endl;
			rmin=min(rmin,V[i].second);
			lmax=max(lmax,V[i].first);
		}
		//cout<<i<<" "<<rmin<<" "<<lmax<<endl;
	}
	if(rmin<lmax) return true;
	else return false;
}

int main()
{	
	
	test(t)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>V[i].first>>V[i].second;
			make_set(i);
		}
		sort(V.begin()+1,V.begin()+n+1);
		ll rmax=-INF;
		for(int i=1;i<=n;i++)
		{
			if(V[i].first>rmax) {rmax=V[i].second;continue;}
			else
			{
				union_set(i,i-1);
				rmax=max(rmax,ma[find_set(i)]);
			}
		}
		set<int> S;
		for(int i=1;i<=n;i++)
		{
			S.insert(find_set(i));
		}
		prin(S);
		if(S.size()==n) cout<<n-1<<endl;
		else
		{
			int f=1;
			for(int i=1;i<=n;i++)
			{
				if(!DON[find_set(i)])
				{
					DON[find_set(i)]=true;
					if(F(find_set(i)))
					{
						cout<<S.size()+1<<endl;
						f=0;
						break;
					}
				}
			}
			if(f)
			{
				cout<<S.size()<<endl;
			}
		}
	}
}