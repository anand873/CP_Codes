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
	int n,k;
	cin>>n>>k;
	vl A(n);
	// int fk=k;
	take(A,0,n);
	vl Pos,Neg;
	for(int i=0;i<n;i++)
	{
		if(A[i]>0) Pos.push_back(A[i]);
		else if(A[i]<0) Neg.push_back(A[i]);
	}

	int pos = Pos.size();
	int neg = Neg.size();
	sort(all(Pos));
	sort(all(Neg));
	if(pos+neg<k)
	{
		cout<<0<<endl;
	}
	else
	{
		if((pos==0&&k%2)||(neg-neg%2+pos<k))
		{
			ll ans=1;
			vl X;
			for(auto x:Pos) X.push_back(x);
			for(auto x:Neg) X.push_back(-x);

			sort(all(X));
			for(int i=0;i<k;i++)
			{
				ans*=X[i];
				ans%=MOD;
			}

			ans*=-1;
			ans%=MOD;
			ans+=MOD;
			if(pos+neg<n) cout<<0<<endl;
			else cout<<ans<<endl;
		}
		else
		{
			ll ans=1;
			int i=0,j=pos-1;

			while(k>=2)
			{
				ll temp1=-1,temp2=-1;
				if(j-1>=0) temp1=Pos[j]*Pos[j-1];
				if(i+1<neg) temp2=Neg[i]*Neg[i+1];

				if(temp1<=temp2)
				{
					i+=2;
					k-=2;
					temp2%=MOD;
					ans*=temp2;
					ans%=MOD;
				}
				else
				{
					j-=2;
					k-=2;
					temp1%=MOD;
					ans*=temp1;
					ans%=MOD;
				}
			}
			if(k)
			{
				if(j>=0) ans*=Pos[j];
				else
				{
					ans*=powN(Pos[j+1],MOD-2);
					ans%=MOD;

					ll temp = Neg[i]*Neg[i+1];
					temp%=MOD;
					ans*=temp;
					ans%=MOD;
				}
				ans%=MOD;
				cout<<ans<<endl;
			}
			else
			{
				cout<<ans<<endl;
			}
		}
	}
}	
