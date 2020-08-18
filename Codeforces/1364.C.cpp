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
#define prin(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int in=f;in<f+n;in++) cin>>V[in]
#define what(x) cerr<<#x<<" = "<<x<<endl
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "

const int MOD = 1e9+7,MAX = 1e6+5;
/////////////////FastExp///////////////////
ll powN(ll a,ll p,ll mod)
{
	if(p==0) return 1;
	ll z=powN(a,p/2,mod);
	z=(z*z)%mod;
	if(p%2) z=(z*a)%mod;
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
	for(int i=2;i<=MAX;i++) if(is_prime[i]) MinDiv[i]=i;
}
//////////////////Sieve////////////////////

int main()
{
	int n;
	cin>>n;
	vi A(n+2);
	take(A,1,n);
	A[n+1]=n+1;
	vi B(n+2);
	B[n+1]=n+1;
	int curr=n+1;
	for(int i=n;i>1;i--)
	{
		if(A[i]==A[i-1])
		{
			B[i]=-1;
		}
		else
		{
			B[i]=A[i-1];
		}
	}
	if(A[1]==0) B[1]=-1;
	else B[1]=0;
	set<int> S;
	for(int i=0;i<=n+10;i++) S.insert(i);
	vi Mo;
	bool can=true;

	for(int i=1;i<=n;i++)
	{
		if(B[i]==-1)
		{
			Mo.push_back(i);
			B[i]=n+1;
		}
		if(S.count(B[i]))
		{
			S.erase(B[i]);
		}
		if(A[i]==*(S.begin()))
		{
			continue;
		}
		else
		{
			while(A[i]!=*(S.begin()))
			{
				if(Mo.size()==0)
				{
					can=false;break;
				}
				B[Mo.back()]=*(S.begin());
				Mo.pop_back();
				S.erase(*(S.begin()));
			}
			if(!can) break;
		}
	}

	if(can)
	{
		for(int i=1;i<=n;i++) cout<<B[i]<<" ";
		cout<<endl;
	}
	else
	{
		cout<<-1<<endl;
	}
}		