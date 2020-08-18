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
	int x,k,y;
	cin>>x>>k>>y;

	vi A(n);
	vi B(m);
	take(A,0,n);
	take(B,0,m);
	set<int> AA,BB;
	bool can=true;
	vi InA;
	int pos=0;
	for(int i=0;i<m;i++)
	{
		while(pos<n&&A[pos]!=B[i])
		{
			pos++;
		}
		if(pos==n)
		{
			can=false;
		}
		else
		{
			InA.push_back(pos);
		}
	}
	if(!can)
	{
		cout<<-1<<endl;
		return 0;
	}
	ll cost = 0;
	int last=-1;
	InA.push_back(n);
	for(auto posit:InA)
	{
		int how = posit-last-1;
		int ma = 0;
		for(int p = last+1;p<posit;p++)
		{
			ma = max(ma,A[p]);
		}
		if(how<k)
		{
			if((posit!=n&&ma<A[posit])||(last!=-1&&ma<A[last]))
			{
				cost += (ll)how*y;
				// what(cost);
			}
			else
			{
				can=false;
				break;
			}
		}
		else
		{
			if((ll)y*k<=x&&(posit!=n&&ma<A[posit]||(last!=-1&&A[last]>ma)))
			{
				cost+=(ll)how*y;
				// cerr<<1<<" ";what(cost);
			}
			else
			{
				int rem = 0;
				set<int> S;
				for(int p =last+1;p<posit;p++) S.insert(p;)
				ma=0;
				if(posit!=n)
				{
					ma=max(ma,A[posit]);
				} 
				if(last!=-1)
				{
					ma=max(ma,A[last]);
				}
				while(S.size()>=k)
				{
					set<int> RE;
					for(auto s:S)
					{ 
						if(A[s]>ma||s+k<posit)
						{
							int x=0;
							while(x<k)
							{
								RE.insert(s+x);
							}
							break;
						}
					}
					cost += 
					for(auto re:RE) S.erase(re);
				}
				for(auto po:S)
				{
					if(A[po])
				}
				cost+= min((ll)rem*y,((ll)(rem%k)*y+(ll)(rem/k)*x));
				// cerr<<3<<" ";what(cost);
			}
		}
		last = posit;
	}
	if(can)
	{
		cout<<cost<<endl;
	}
	else cout<<-1<<endl;

}	