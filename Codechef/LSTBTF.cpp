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

#define test(t) int t;cin>>t;while(t--)
#define forn(i,n) for(i=0;i<n;i++)
#define rforn(i,n) for(i=n-1;i>=0;i--)
#define all(v) (v).begin(),(v).end()
const int MOD = 1e9+7,MAX = 1e5+5;
ll powN(ll a,ll p)
{
	if(p==0) return 1;
	ll z=powN(a,p/2);
	z=(z*z)%MOD;
	if(p%2) z=(z*a)%MOD;
	return z;
}
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
ll modInv(ll a)
{
	return powN(a,MOD-2);
}

int f(int a)
{
	return a*a-1;
}

int main()
{
	test(t)
	{
		int n;
		cin>>n;
		int p=sqrt(n);
		int fl=0;
		if(p*p==n)
		{
			//cout<<"YO"<<endl;
			int j;
			forn(j,n) cout<<"1";
			cout<<endl;
			fl=1;
			goto en;
		}
		p++;
		vector<pair<int,vector<char>>> V
		for(;p*p<81*n;p++)
		{
			vector<int> A(10);
			int i=9;
			int x=p*p-n;
			int l=0;
			while(x&&i>1)
			{
				A[i]=x/f(i);
				x%=f(i);
				l+=A[i];
				i--;
			}
			if(l>n) continue;
			A[1]=n-l;
			if(x>0) continue;
			else
			{
				fl=1;
				vector<char> S;
				for(i=1;i<10;i++)
				{
					int j;
					for(j=0;j<A[i];j++)
						S.push_back(i);
				}
				V.push_back(l,S);
			}
		}
		sort(all(V));
		if(fl==0) cout<<-1<<endl;
		en:;
	}
}