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
///////////////////PnC/////////////////////
vl Fac(MAX),Inv(MAX);
void CalcFac()
{
	Fac[0]=Inv[0]=1;
	for(int i=1;i<MAX;i++)
	{
		Fac[i]=(Fac[i-1]*i)%MOD;
		Inv[i]=powN(Fac[i],MOD-2);
	}
}

ll NCR(int n,int r)
{
	if(r>n) return 0;
	return (((Fac[n]*Inv[r])%MOD)*Inv[n-r])%MOD;
}
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

int main()
{
	int n,m;
	cin>>n>>m;
	set<int> R;
	for(int i=0;i<n;i++)
	{
		R.insert(i);
	}

	vector<vpii> M(n);
	vector<set<int>> ND(n);
	vvi X(n,vi(m));
	// for(int i=0;i<n;i++) X[i][0]=1;

	for(int i=0;i<n;i++)
	{
		int k;
		cin>>k;
		for(int j=0;j<k;j++)
		{
			ND[i].insert(j);
			int l,r;
			cin>>l>>r;
			l--;
			r--;
			M[i].push_back({l,r});
		}
	}
	while(R.size())
	{
		prinv(R);
		int mincol=m;
		for(auto r:R)
		{
			int f = *(ND[r].begin());
			int l = M[r][f].first;
			mincol = min(l,mincol); 
		}
		set<int> TE;
		for(auto r:R)
		{
			int col=-1;
			for(int j=0;j<M[r].size();j++)
			{
				if(M[r][j].first<=mincol&&M[r][j].second>=mincol)
				{
					col = j;
					break;
				}
			}

			if(ND[r].count(col))
			{
				X[r][mincol]=1;
				ND[r].erase(col);
			}
			
			if(ND[r].size()==0) TE.insert(r);
		}
		for(auto te:TE) R.erase(te);

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cout<<X[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	int x = 0;
	for(int j=0;j<m;j++)
	{
		int col=0;
		for(int i=0;i<n;i++)
		{
			col+=X[i][j];
		}
		x+=col*col;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<X[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<x<<endl;
}	