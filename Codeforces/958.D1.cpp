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

const int MOD = 1e9+7,MAX = 1e5+5;
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

int main()
{
	int m;
	cin>>m;
	vector<double> A(m);
	map<double,int> M;
	for(int j=0;j<m;j++)
	{
		string s;
		cin>>s;
		int a=0,b=0,c=0;
		int i=s.length()-1;
		int place=1;
		while(s[i]!='/')
		{
			c+=place*(s[i]-'0');
			place*=10;
			i--;
		}
		place=1;
		i-=2;
		while(s[i]!='+')
		{
			b+=place*(s[i]-'0');
			place*=10;
			i--;
		}
		place=1;
		i--;
		while(s[i]!='(')
		{
			a+=place*(s[i]-'0');
			place*=10;
			i--;
		}
		M[(a+b)*1.0/c]++;
		A[j]=(a+b)*1.0/c;
	}
	for(int i=0;i<m;i++)
	{
		cout<<M[A[i]]<<" ";
	}
	cout<<endl;
}		