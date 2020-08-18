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

const int MOD = 1e9+7,MAX = 1e5+5;
const ll INF = 9e18+5;
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

pii R90(pii X, pii C)
{
	int x=X.first,y=X.second;

	int cx=C.first,cy=C.second;

	int diffx=x-cx;
	int diffy=y-cy;

	swap(diffx,diffy);
	diffx*=-1;
	return {cx+diffx,cy+diffy};
}

int dist(pii a, pii b)
{
	return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}

bool is_rect(vpii P)
{
	sort(all(P));
	// for(int i=0;i<P.size();i++)
	// {
	// 	cout<<P[i].first<<","<<P[i].second<<" ";
	// }
	// cout<<endl;
	if(P[0]==P[1]||P[1]==P[2]||P[2]==P[3]||P[3]==P[1]) return false;
	if(dist(P[0],P[1])!=dist(P[0],P[2])) return false;
	if(dist(P[3],P[1])!=dist(P[3],P[2])) return false;
	if(dist(P[1],P[0])!=dist(P[1],P[3])) return false;

	if(dist(P[0],P[3])!=dist(P[1],P[2])) return false;

	return true; 
}

int main()
{
	int n;
	cin>>n;

	bool can=true;
	
	for(int g=0;g<n;g++)
	{
		vector<vector<pii>> P(4);
		for(int i=0;i<4;i++)
		{
			int x,y,cx,cy;
			cin>>x>>y>>cx>>cy;
			// cerr<<x<<","<<y<<" ";
			P[i].push_back({x,y});
			for(int j=0;j<3;j++)
			{
				P[i].push_back(R90(P[i].back(),{cx,cy})); 
				// cerr<<P[i].back().first<<","<<P[i].back().second<<" ";
			}
			// cout<<endl;
		}

		int ans=MOD;
		bool form=false;
		for(int fi=0;fi<4;fi++)
		{
			for(int se=0;se<4;se++)
			{
				for(int th=0;th<4;th++)
				{
					for(int fo=0;fo<4;fo++)
					{
						if(is_rect({P[0][fi],P[1][se],P[2][th],P[3][fo]}))
						{
							ans=min(ans,fi+se+th+fo);
							form=true;
						}
					}
				}
			}
		}
		if(!form) cout<<-1<<endl;
		else cout<<ans<<endl;
	}
	// if(can) cout<<ans<<endl;
	// else cout<<-1<<endl;
}	