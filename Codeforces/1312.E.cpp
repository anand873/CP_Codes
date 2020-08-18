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
#define forn(i,f,n) for(int i=f;i<f+n;i++)
#define rforn(i,l,n) for(int i=l;i>l-n;i--)
#define all(v) v.begin(),v.end()
#define prin(V) for(auto v:V) cout<<v<<" ";cout<<endl
#define take(V,f,n) for(int i=f;i<f+n;i++) cin>>V[i]
#define what(x) cerr<<#x<<" = "<<x<<endl
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "

const ll MOD = 998244353,MAX = 200005;
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

int main()
{	
	int n;
	cin>>n;
	vi A(n+2);
	take(A,1,n);
	for(int num=1;num<2000;num++)
	{
		vi df(n+2),db(n+2);
		df[n]=1;
		db[1]=1;
		for(int i=2;i<=n;i++)
		{
			if(A[i]==A[i-1]-1) db[i]=db[i-1]+1;
			else db[i]=1;
		}
		for(int i=n-1;i>0;i--)
		{
			if(A[i]==A[i+1]-1) df[i]=df[i+1]+1;
			else df[i]=1;
		}
		vi B;
		B.push_back(0);
		int i=1;
		while(i<=n)
		{
			while(A[i]!=num&&i<=n) {B.push_back(A[i]);i++;}
			int st=i;
			while(A[i]==num&&i<=n) i++;
			int en=i-1;
			if(en-st==1)
			{
				B.push_back(num+1);
			}
			else
			{
				if(A[en]+1==A[en+1]&&A[st]+1!=A[st-1])
				{
					if((en-st+1)%2)
						B.push_back(num);
					for(int j=en;j>st;j-=2)
					{
						B.push_back(num+1);
					}
				}
				else if(A[en]+1!=A[en+1]&&A[st]+1==A[st-1])
				{
					for(int j=st;j<en;j+=2)
					{
						B.push_back(num+1);
					}
					if((en-st+1)%2)
						B.push_back(num);
				}
				else //if(A[en]+1==A[en+1]&&A[st]+1==A[st-1])
				{
					if(df[en+1]>db[st-1])
					{
						if((en-st+1)%2)
							B.push_back(num);
						for(int j=en;j>st;j-=2)
						{
							B.push_back(num+1);
						}
					}
					else
					{
						for(int j=st;j<en;j+=2)
						{
							B.push_back(num+1);
						}
						if((en-st+1)%2)
							B.push_back(num);
					}
				}
				// else
				// {
				// 	if(A[en+1]>A[st-1])
				// 	{
				// 		if((en-st+1)%2)
				// 			B.push_back(num);
				// 		for(int j=en;j>st;j-=2)
				// 		{
				// 			B.push_back(num+1);
				// 		}
				// 	}
				// 	else
				// 	{
				// 		for(int j=st;j<en;j+=2)
				// 		{
				// 			B.push_back(num+1);
				// 		}
				// 		if((en-st+1)%2)
				// 			B.push_back(num);
				// 	}
				// }
			}
		}
		//prin(B);
		A=B;
		A.push_back(0);
		//prin(A);
		n=A.size()-2;
	}
	cout<<A.size()-2<<endl;
}		