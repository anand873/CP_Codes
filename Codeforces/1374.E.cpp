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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main()
{
	int n,k;
	cin>>n>>k;
	set<int> Alice,Bob;
	vvi T;
	for(int i=0;i<n;i++)
	{
		int t,a,b;
		cin>>t>>a>>b;
		T.push_back({t,a,b});
	}
	sort(all(T));
	int tim=0;
	set<pii> OA,OB;
	int a=0,b=0;
	int curra=0,currb=0;
	for(auto book:T)
	{
		if(book[1]==0&&book[2]==0) continue;

		else if(book[1]==1&&book[2]==1)
		{
			if(OA.size()==0&&OB.size()==0&&a<k&&b<k)
			{
				a++;
				b++;
				tim+=book[0];
			}
			else if(OA.size()&&OB.size()==0&&b<k)
			{
				int timmin=(*(OA.begin())).first;
				if(a==k) 
				{
					a--;
					tim+=timmin;
					OA.erase(*(OA.begin()));
				}	
				tim+=book[0];
				b++;
				a++;
				
			}
			else if(OB.size()&&OA.size()==0&&a<k)
			{
				int timmin=(*(OB.begin())).first;
				if(b==k) 
				{
					tim+=timmin;
					OB.erase(*(OB.begin()));
					b--;
				}
				tim+=book[0];
				a++;
				b++;
				
			}
			else
			{
				int tima = (*(OA.begin())).first;
				int timb = (*(OB.begin())).first;
				if(-tima-timb>=book[0]&&a==k&&b==k)
				{
					tim+=tima;
					tim+=timb;
					tim+=book[0];
					OB.erase(*(OB.begin()));
					OA.erase(*(OA.begin()));
				}
			}
		}
		else if(book[1]==1)
		{
			if(a<k)
			{
				OA.insert({-book[0],curra});
				curra++;
				tim+=book[0];
				a++;
			}
		}
		else
		{
			if(b<k)
			{
				b++;
				tim+=book[0];
				OB.insert({-book[0],currb});
				currb++;
			}
		}
	}
	if(a<k&&b<k) cout<<-1<<endl;
	else cout<<tim<<endl;
}	