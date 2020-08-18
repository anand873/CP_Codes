//Author: AnandRaj anand873
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
#define prin(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int in=f;in<f+n;in++) cin>>V[in]
#define what(x) cerr<<#x<<" = "<<x<<endl
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "

const int MOD = 1e9+7,MAX = 5e5+5;
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
vector<bool> is_prime(MAX, true);
vector<int> MinDiv(MAX);
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
}
//////////////////Sieve////////////////////

vl F(MAX),Inv(MAX);

ll C(int n,int r)
{
	if(r>n) return 0;
	else return (((F[n]*Inv[r])%MOD)*Inv[n-r])%MOD;
}

int main()
{
	int n,l,k;
	cin>>n>>l>>k;
	F[0]=1;
	Inv[0]=1;
	for(ll i=1;i<=n;i++)
	{
		F[i]=(i*F[i-1])%MOD;
		Inv[i]=powN(F[i],MOD-2);
	}
	vl A(n);
	take(A,0,n);
	sort(all(A));
	ll ans=0;
	for(int i=0;i+l<=n;i++)
	{
		int low=i+1,high=n-1;
		int ind=-1;
		while(low<=high)
		{
			int mid=low+(high-low)/2;
			if(A[mid]>A[i]+k)
			{
				high=mid-1;
			}
			else {ind=mid;low=mid+1;}
		}
		ans+=C(ind-i,l-1);
		ans%=MOD;
	}
	cout<<ans<<endl;

}		